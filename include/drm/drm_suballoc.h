#ifndef __BACKPORT_DRM_SUBALLOC_H__
#define __BACKPORT_DRM_SUBALLOC_H__
#if LINUX_VERSION_CODE >= KERNEL_VERSION(7, 1, 0)
#include_next <drm/drm_suballoc.h>
#else
#define drm_suballoc_alloc LINUX_BACKPORT(drm_suballoc_alloc)
#define drm_suballoc_insert LINUX_BACKPORT(drm_suballoc_insert)
#include_next <drm/drm_suballoc.h>

struct drm_suballoc *drm_suballoc_alloc(gfp_t gfp);
int drm_suballoc_insert(struct drm_suballoc_manager *sa_manager,
			struct drm_suballoc *sa, size_t size,
			bool intr, size_t align);

#endif
#endif