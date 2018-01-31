#include "Interface.h"

void InterfaceInit(int argc, char *argv[])
{
    GtkWidget *okno;
    GtkWidget *image, *image2;
    GtkWidget *vbox;

    gtk_init (&argc, &argv);

    okno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position (GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
    gtk_window_set_title (GTK_WINDOW(okno), "Project test");
    gtk_container_set_border_width (GTK_CONTAINER(okno), 5);

    vbox = gtk_box_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(okno), vbox);

    image=gtk_image_new_from_file(argv[1]);
    image2=gtk_image_new_from_file(argv[2]);

    gtk_box_pack_start (GTK_BOX(vbox), image, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), image2, TRUE, TRUE, 0);

    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(okno);


    gtk_main ();
}
