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

#include "goci-image.h"

G_DEFINE_TYPE (GociImage, goci_image, GOCI_TYPE_JSON);

static void
goci_image_finalize (GObject *object)
{
  GociImage *self = (GociImage *) object;

  g_free (self->created);
  g_free (self->author);
  g_free (self->architecture);
  g_free (self->os);
  g_clear_object (&self->rootfs);
  g_clear_object (&self->config);
  g_list_free_full (self->history, g_object_unref);

  G_OBJECT_CLASS (goci_image_parent_class)->finalize (object);
}

static void
goci_image_class_init (GociImageClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociImage, created, "created"),
    GOCI_JSON_STRING_PROP (GociImage, author, "author"),
    GOCI_JSON_STRING_PROP (GociImage, architecture, "architecture"),
    GOCI_JSON_STRING_PROP (GociImage, os, "os"),
    GOCI_JSON_OBJECT_PROP (GociImage, config, "config", goci_image_config_get_type),
    GOCI_JSON_OBJECT_PROP (GociImage, rootfs, "rootfs", goci_image_rootfs_get_type),
    GOCI_JSON_OBJECTLIST_PROP (GociImage, history, "history", goci_image_history_get_type),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_image_finalize;
  json_class->props = props;

}

static void
goci_image_init (GociImage *self)
{
}
