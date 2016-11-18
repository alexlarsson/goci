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

#include "goci-image-history.h"

G_DEFINE_TYPE (GociImageHistory, goci_image_history, GOCI_TYPE_JSON);

static void
goci_image_history_finalize (GObject *object)
{
  GociImageHistory *self = (GociImageHistory *) object;

  g_free (self->created);
  g_free (self->created_by);
  g_free (self->author);
  g_free (self->comment);

  G_OBJECT_CLASS (goci_image_history_parent_class)->finalize (object);
}


static void
goci_image_history_class_init (GociImageHistoryClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociImageHistory, created, "created"),
    GOCI_JSON_STRING_PROP (GociImageHistory, created_by, "created_by"),
    GOCI_JSON_STRING_PROP (GociImageHistory, author, "author"),
    GOCI_JSON_STRING_PROP (GociImageHistory, comment, "comment"),
    GOCI_JSON_BOOL_PROP (GociImageHistory, empty_layer, "empty_layer"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_image_history_finalize;
  json_class->props = props;
}

static void
goci_image_history_init (GociImageHistory *self)
{
}
