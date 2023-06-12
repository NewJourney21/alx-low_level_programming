#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_elf_type(unsigned int e_type);
void display_entry_point(unsigned long int e_entry);

/**
 * display_magic - Displays the magic numbers from the ELF header.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void display_magic(unsigned char *e_ident)
{
	printf("  Magic:  ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * display_class - Displays the class of the ELF file.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void display_class(unsigned char *e_ident)
{
	printf("  Class:                            ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	case ELFCLASSNONE:
		printf("none\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * display_data - Displays the data encoding of the ELF file.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void display_data(unsigned char *e_ident)
{
	printf("  Data:                             ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	case ELFDATANONE:
		printf("none\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * display_version - Displays the version of the ELF file.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void display_version(unsigned char *e_ident)
{
	printf("  Version:                          %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
	}
}

/**
 * display_osabi - Displays the OS/ABI of the ELF file.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void display_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                           ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
