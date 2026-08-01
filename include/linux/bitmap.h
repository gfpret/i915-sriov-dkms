#include_next <linux/bitmap.h>

#ifndef __BACKPORT_LINUX_BITMAP_H__
#define __BACKPORT_LINUX_BITMAP_H__

#if LINUX_VERSION_CODE < KERNEL_VERSION(7, 1, 0)
#define __bitmap_weighted_or LINUX_BACKPORT(__bitmap_weighted_or)
#define __bitmap_weighted_xor LINUX_BACKPORT(__bitmap_weighted_xor)

unsigned int __bitmap_weighted_or(unsigned long *dst, const unsigned long *bitmap1,
				  const unsigned long *bitmap2, unsigned int nbits);
unsigned int __bitmap_weighted_xor(unsigned long *dst, const unsigned long *bitmap1,
				  const unsigned long *bitmap2, unsigned int nbits);

#define bitmap_weighted_or LINUX_BACKPORT(bitmap_weighted_or)
#define bitmap_weighted_xor LINUX_BACKPORT(bitmap_weighted_xor)

static __always_inline
unsigned int bitmap_weighted_or(unsigned long *dst, const unsigned long *src1,
				const unsigned long *src2, unsigned int nbits)
{
	if (small_const_nbits(nbits)) {
		*dst = *src1 | *src2;
		return hweight_long(*dst & BITMAP_LAST_WORD_MASK(nbits));
	} else {
		return __bitmap_weighted_or(dst, src1, src2, nbits);
	}
}

static __always_inline
unsigned int bitmap_weighted_xor(unsigned long *dst, const unsigned long *src1,
				const unsigned long *src2, unsigned int nbits)
{
	if (small_const_nbits(nbits)) {
		*dst = *src1 ^ *src2;
		return hweight_long(*dst & BITMAP_LAST_WORD_MASK(nbits));
	} else {
		return __bitmap_weighted_xor(dst, src1, src2, nbits);
	}
}
#endif

#endif