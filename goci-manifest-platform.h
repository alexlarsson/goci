/*
 * Copyright © 2016 Red Hat, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Alexander Larsson <alexl@redhat.com>
 */

#ifndef __GOCI_MANIFEST_PLATFORM_H__
#define __GOCI_MANIFEST_PLATFORM_H__

#include "goci-json.h"

G_BEGIN_DECLS

#define GOCI_TYPE_MANIFEST_PLATFORM goci_manifest_platform_get_type ()
G_DECLARE_FINAL_TYPE (GociManifestPlatform, goci_manifest_platform, GOCI, MANIFEST_PLATFORM, GociJson)

struct _GociManifestPlatform
{
  GociJsonClass parent_class;

  char *architecture;
  char *os;
  char *os_version;
  char **os_features;
  char *variant;
  char **features;
};

struct _GociManifestPlatformClass
{
  GociJsonClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_MANIFEST_PLATFORM_H__ */
