#ifndef __BACKPORT_DRM_RAS_GENL_FAMILY_H__
#define __BACKPORT_DRM_RAS_GENL_FAMILY_H__
#if LINUX_VERSION_CODE >= KERNEL_VERSION(7, 1, 0)
#include_next <drm/drm_ras_genl_family.h>
#else
#define drm_ras_genl_family_register LINUX_BACKPORT(drm_ras_genl_family_register)
#define drm_ras_genl_family_unregister LINUX_BACKPORT(drm_ras_genl_family_unregister)
static inline int drm_ras_genl_family_register(void) { return 0; }
static inline void drm_ras_genl_family_unregister(void) { }
#endif
