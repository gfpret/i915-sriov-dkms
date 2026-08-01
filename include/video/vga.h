#include_next <video/vga.h>
#ifndef __BACKPORT_VIDEO_VGA_H__
#define __BACKPORT_VIDEO_VGA_H__

#if LINUX_VERSION_CODE < KERNEL_VERSION(7, 1, 0)
#define VGA_IS0_R	0x3C2	/* Input Status Register 0 */
#endif

#endif