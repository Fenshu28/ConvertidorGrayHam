#include <gtk/gtk.h>

#define MAXi 60

GtkWidget *txtDato1, *txtDato2, *cmbOpc, *lbResul, *FrmDialog, *window;
GString *Dato;

const char *Opciones[] = {"Selecciona una opción","Binario a Gray","Gray a Binario","Código Hamming","Errores en Hammings","Suma de números BDC"}; 

static void activate_win(GtkApplication *app, gpointer user_data){
	GtkWidget *main_box,*lbDato1,*lbDato2,*btnBox, *btnCalc;
	
	Dato = g_string_new("");
	
    // Creando el contenedor y agregandolo al windows
	main_box = gtk_fixed_new();
    
    // Creando el combo  de opciones
    cmbOpc = gtk_combo_box_text_new();
    for (int i = 0; i < G_N_ELEMENTS(Opciones); i++){
		gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(cmbOpc), Opciones[i]);
	}
	gtk_combo_box_set_active (GTK_COMBO_BOX (cmbOpc), 0);
    
    // Creando los cuadro de textos
    txtDato1 = gtk_entry_new();
    txtDato2 = gtk_entry_new();
    lbDato1 = gtk_label_new("Código Gray:");
    lbDato2 = gtk_label_new("Código Hamming:");
    
    // Cre
    
    // Señales
    
    // Añadiendo componentes al contenedor principal main_box.
    gtk_fixed_put(GTK_FIXED(main_box),cmbOpc, 70, 20);
    gtk_fixed_put(GTK_FIXED(main_box),lbDato1, 80, 60);
    gtk_fixed_put(GTK_FIXED(main_box),txtDato1, 80, 80);
    gtk_fixed_put(GTK_FIXED(main_box),lbDato2, 80, 120);
    gtk_fixed_put(GTK_FIXED(main_box),txtDato2, 80, 140);
    
    
    
    
    // Crea la ventana
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Convertidor de números Gray y Hamming");
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 350);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // Añade el contenedor fixed a la ventana
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // Mostrar todos los componentes
    gtk_widget_show_all(window);
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
