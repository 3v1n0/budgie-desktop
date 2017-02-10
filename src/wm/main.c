/*
 * This file is part of budgie-desktop
 *
 * Copyright © 2015-2017 Ikey Doherty <ikey@solus-project.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <meta/main.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int ret = META_EXIT_ERROR;
        GOptionContext *context = NULL;
        GError *error = NULL;

        /* Initialise meta variables */
        context = meta_get_option_context();
        if (!g_option_context_parse(context, &argc, &argv, &error)) {
                goto clean;
        }

        /* TODO: Initialise the actual plugin type */
        meta_set_gnome_wm_keybindings("Mutter,GNOME Shell");
        meta_set_wm_name("Mutter(Budgie)");

        /* Fix environment */
        g_setenv("NO_GAIL", "1", TRUE);
        g_setenv("NO_AT_BRIDGE", "1", TRUE);

clean:
        if (error) {
                g_printerr("Unknown option: %s\n", error->message);
                g_error_free(error);
        }
        g_option_context_free(context);
        return ret;
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 expandtab:
 * :indentSize=8:tabSize=8:noTabs=true:
 */
