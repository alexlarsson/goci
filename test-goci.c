#include "goci.h"

int
main ()
{
  g_autoptr(GociJson) json = NULL;
  g_autoptr(GociVersioned) versioned = NULL;
  g_autoptr(GociVersioned) versioned2 = NULL;
  g_autoptr(GociJson) image = NULL;
  g_autoptr(JsonParser) parser = json_parser_new ();
  g_autoptr(JsonParser) parser2 = json_parser_new ();
  g_autoptr(JsonParser) parser3 = json_parser_new ();
  g_autoptr(GError) error = NULL;

  if (!json_parser_load_from_file (parser, "manifest.json", &error))
    {
      g_printerr ("can't load manifest, %s\n", error->message);
      return 1;
    }

  versioned = goci_versioned_from_json (json_parser_get_root (parser), NULL);
  g_print ("Version: %d mediatype: %s\n", versioned->version, versioned->mediatype);
  g_print ("manifest to-string:\n%s\n",
           json_to_string (goci_json_to_node (GOCI_JSON (versioned)),
                           TRUE));

  if (!json_parser_load_from_file (parser2, "image.json", NULL))
    {
      g_printerr ("can't load image\n");
      return 1;
    }

  image = goci_json_from_node (json_parser_get_root (parser2), GOCI_TYPE_IMAGE, &error);
  if (image == NULL)
    {
      g_print ("error: %s\n", error->message);
      return 1;
    }
  g_print ("manifest to-string:\n%s\n",
           json_to_string (goci_json_to_node (GOCI_JSON (image)),
                           TRUE));


  if (!json_parser_load_from_file (parser3, "manifest-list.json", NULL))
    {
      g_printerr ("can't load manifest list\n");
      return 1;
    }

  versioned2 = goci_versioned_from_json (json_parser_get_root (parser3), &error);
  if (versioned2 == NULL)
    {
      g_print ("error: %s\n", error->message);
      return 1;
    }
  g_print ("manifest to-string:\n%s\n",
           json_to_string (goci_json_to_node (GOCI_JSON (versioned2)),
                           TRUE));
}
