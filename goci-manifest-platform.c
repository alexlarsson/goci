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

#include "config.h"

#include <string.h>

#include "goci-manifest-platform.h"

G_DEFINE_TYPE (GociManifestPlatform, goci_manifest_platform, GOCI_TYPE_JSON);

static void
goci_manifest_platform_finalize (GObject *object)
{
  GociManifestPlatform *self = (GociManifestPlatform *) object;

  g_free (self->architecture);
  g_free (self->os);
  g_free (self->os_version);
  g_strfreev (self->os_features);
  g_free (self->variant);
  g_strfreev (self->features);

  G_OBJECT_CLASS (goci_manifest_platform_parent_class)->finalize (object);
}


static void
goci_manifest_platform_class_init (GociManifestPlatformClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociManifestPlatform, architecture, "architecture"),
    GOCI_JSON_STRING_PROP (GociManifestPlatform, os, "os"),
    GOCI_JSON_STRING_PROP (GociManifestPlatform, os_version, "os.version"),
    GOCI_JSON_STRING_PROP (GociManifestPlatform, variant, "variant"),
    GOCI_JSON_STRV_PROP (GociManifestPlatform, os_features, "os.features"),
    GOCI_JSON_STRV_PROP (GociManifestPlatform, features, "features"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_manifest_platform_finalize;
  json_class->props = props;
}

static void
goci_manifest_platform_init (GociManifestPlatform *self)
{
}
