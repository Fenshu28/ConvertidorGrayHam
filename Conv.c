#include <gtk/gtk.h>

#define MAXi 60

GtkWidget *txtDato, *cmbTipo, *lbResul, *FrmDialog, *window;
GString *Dato;

const char *Opciones[] = {"Selecciona una opción","Binario a Gray","Gray a Binario","Código Hamming","Errores en Hammings","Suma de números BDC"}; 

static void activate_win(GtkApplication *app, gpointer user_data){
	GtkWidget *main_box,*lbDato,*btnBox, *btnCalc;
	
	Dato = g_string_new("");
	
    // Crea el contenedor
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Cajas de Botones");

  g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (gtk_main_quit),NULL);
      gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  main_box = gtk_vbox_new(FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), main_box);
      gtk_widget_show_all (window);
}

 void MsgBox(char *aviso){
	 FrmDialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"%s",aviso);
	 gtk_dialog_run(GTK_DIALOG(FrmDialog));
	 gtk_widget_destroy(FrmDialog);
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
