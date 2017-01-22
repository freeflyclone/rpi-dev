## Workflow

While the rpi in all it's flavors does many things well, as a serious development platform it comes up short in one key area: iteration speed.  The classic edit-compile-test-repeat cycle is hampered by the use of an SD card as primary storage.  For many end-users this not a concern.  For the hard-core developer, its a nuisance at best and can be extremely annoying. Additionally SD cards are subject to quality differences, have long term read/write issues, and in general can introduce uncertainty in a development environment. Happily, there's a solution: cross-compiling from a Linux development host.

### Host Selection

The author's development machine is a 4Ghz Core i7, with 32GB of RAM, 256GB of SSD and Ubuntu 16.04. It's a DIY machine, chosen to be the fastest possible for the lowest cost. The SSD really makes a difference, probably the most important single upgrade one can choose.  Ubuntu 16.04 is the Linux distro of choice, mostly because it uses GCC 5.4.  GCC 5 supports Unicode fully, and that was deemed important.

### Prerequisites

Ubuntu 16.04 comes well equipped as a cross-compiling host.  There are a few additional packages that need to be installed:

    sudo apt install minicom g++-arm-linux-gnueabihf xinetd tftpd tftp nfs-kernel-server device-tree-compiler
     
Depending on your particular 16.04 installation, some of these may already exist.

To eliminate the SD card I/O bottleneck from the development environment, we'll use 2 standard tricks:
* booting from the Host with tftpboot
* using NFS services for the rpi's filesystem

### Server Setup - tftpboot

Execute the following to install a service for *tftpd* in the xinetd configuration:

    sudo tee /etc/xinetd.d/tftp > /dev/null << EOF
    service tftp
    {
        protocol        = udp
        port            = 69
        socket_type     = dgram
        wait            = yes
        user            = nobody
        server          = /usr/sbin/in.tftpd
        server_args     = /tftpboot
        disable         = no
    }
    EOF

With the service installed, create a folder to match *server_args* in the above service description:

    sudo mkdir /tftpboot
    sudo chmod -R 777 /tftpboot
    sudo chown -R nobody /tftpboot

Restart the *xinetd* service:

    sudo /etc/init.d/xinetd restart
    
Create a sample file for testing the server:

    echo This is readme.txt from the tftp server > /tftpboot/readme.txt

Verify that the tftpd server is working:

    tftp localhost

Since tftp is interactive, you'll receive a prompt *tftp>*
The following commands should be issued to that prompt:

    get readme.txt
    quit

If all went well, the *readme.txt* will be in your local directory where you invoked __tftp__ from.  It may be necessary to add port 69 to your firewall's list of allowed ports, if you're running one.

Be advised that there is no security with tftp.  It is left as an exercise to the reader to secure it if need be.

### Server Setup - NFS

There's a great [guide](https://www.digitalocean.com/community/tutorials/how-to-set-up-an-nfs-mount-on-ubuntu-16-04) for setting up an NFS server written by [Melissa Anderson](https://www.digitalocean.com/community/users/melissaanderson) over at [DigitalOcean](https://www.digitalocean.com).  It's highly recommended!
