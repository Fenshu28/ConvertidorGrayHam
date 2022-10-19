#include <gtk/gtk.h>

static void activate_win(GtkApplication *app, gpointer user_data){
	
}

int main(int argc, char **argv){
	GtkApplication *app;
    int status;

    // Inicializa la ventana
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate_win), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
}
