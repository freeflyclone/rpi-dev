## Workflow

While the rpi in all it's flavors does many things well, as a serious development platform it comes up short in one key area: iteration speed.  The classic edit-compile-test-repeat cycle is hampered by the use of an SD card as primary storage.  For many end-users this not a concern.  For the hard-core developer, its a nuisance at best and can be extremely annoying. Additionally SD cards are subject to quality differences, have long term read/write issues, and in general can introduce uncertainty in a development environment. Happily, there's a solution: cross-compiling from a Linux development host.

### Host Selection

The author's development machine is a 4Ghz Core i7, with 32GB of RAM, 256GB of SSD and Ubuntu 16.04. It's a DIY machine, chosen to be the fastest possible for the lowest cost. The SSD really makes a difference, probably the most important single upgrade one can choose.  Ubuntu 16.04 is the Linux distro of choice, mostly because it uses GCC 5.4.  GCC 5 supports Unicode fully, and that was deemed important.

### Prerequisites

Ubuntu 16.04 comes well equipped as a cross-compiling host.  There are a few additional packages that need to be installed:

    sudo apt install minicom g++-arm-linux-gnueabihf nfs-kernel-server device-tree-compiler
     
Depending on your particular 16.04 installation, some of thes may already exist.

### NFS Server setup

There's a great [guide](https://www.digitalocean.com/community/tutorials/how-to-set-up-an-nfs-mount-on-ubuntu-16-04) for setting up an NFS server at [DigitalOcean](https://www.digitalocean.com)
