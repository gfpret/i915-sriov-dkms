#include_next <linux/gfp.h>

#ifndef __BACKPORT_LINUX_GFP_H__
#define __BACKPORT_LINUX_GFP_H__

/* Helper macro to avoid gfp flags if they are the default one */
#ifndef __default_gfp
#define __default_gfp(a,...) a
#endif

#ifndef default_gfp
#define default_gfp(...) __default_gfp(__VA_ARGS__ __VA_OPT__(,) GFP_KERNEL)
#endif

#endif
