MEMORY 
{
	ram : ORIGIN = 0x200000, LENGTH = 0x1000
}

SECTIONS 
{
	.text : { *(.text*) } > ram
	.bss : { *(.bss*) } > ram
}
