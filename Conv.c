#include <gtk/gtk.h>

#define MAXi 60

GtkWidget *txtDato1, *txtDato2,*lbDato1,*lbDato2, *lbDesc,*cmbOpc, *lbResul, *FrmDialog, *window;
GString *Dato1, *Dato2;

const char *Opciones[] = {"Selecciona una opción","Binario a Gray","Gray a Binario","Código Hamming","Errores en Hammings","Suma de números BDC"}; 

void MsgBox(char *aviso){
	 FrmDialog = gtk_message_dialog_new(GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"%s",aviso);
	 gtk_dialog_run(GTK_DIALOG(FrmDialog));
	 gtk_widget_destroy(FrmDialog);
 }

int valid(GString *Data){
	int len = Data->len;
	 	 	 
	for(int i = 0; i < len; i++){		 
		if((Data->str[i] != 48) && (Data->str[i] != 49)){
			MsgBox("Solo ingresa 0 y 1.");
			return 1;
		}
	}
}

void calcular(){
	g_print("\nCalculando...\n\n");
	
	if((Dato1->len > 0) || (Dato2->len > 0)){
		GString *Result = g_string_new("");
		char Bina[MAXi] = {},Gray[MAXi] = {},Hamm[MAXi] = {},BCD1[MAXi] = {},BDC2[MAXi] = {};
		int pos;
		
		if(valid(Dato1) || valid(Dato2)){
			return;
		}
		
		
		
		
	}else{
		MsgBox("Debe acompletar los campos.");
	}
	
	
}

void change_layout(GtkWidget *widget, gpointer data){
	gtk_widget_set_visible(lbDesc,FALSE);
	switch (gtk_combo_box_get_active(GTK_COMBO_BOX(cmbOpc)))
	{
		case 1:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,TRUE);
			gtk_widget_set_visible(txtDato2,FALSE);
			gtk_widget_set_visible(lbDato1,TRUE);
			gtk_widget_set_visible(lbDato2,FALSE);
			// Cambio de etiquetas
			gtk_label_set_text(GTK_LABEL(lbDato1),"Código Binario");
			
			break;
		case 2:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,TRUE);
			gtk_widget_set_visible(txtDato2,FALSE);
			gtk_widget_set_visible(lbDato1,TRUE);
			gtk_widget_set_visible(lbDato2,FALSE);
			
			// Cambio de etiquetas
			gtk_label_set_text(GTK_LABEL(lbDato1),"Código Gray");
						
			break;
		case 3:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,TRUE);
			gtk_widget_set_visible(txtDato2,FALSE);
			gtk_widget_set_visible(lbDato1,TRUE);
			gtk_widget_set_visible(lbDato2,FALSE);
			// Cambio de etiquetas
			gtk_label_set_text(GTK_LABEL(lbDato1),"Código Hamming");
			
			break;
		case 4:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,TRUE);
			gtk_widget_set_visible(txtDato2,FALSE);
			gtk_widget_set_visible(lbDato1,TRUE);
			gtk_widget_set_visible(lbDato2,FALSE);
			// Cambio de etiquetas
			gtk_label_set_text(GTK_LABEL(lbDato1),"Código Hamming recibido");
			
			break;
		case 5:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,TRUE);
			gtk_widget_set_visible(txtDato2,TRUE);
			gtk_widget_set_visible(lbDato1,TRUE);
			gtk_widget_set_visible(lbDato2,TRUE);
			// Cambio de etiquetas
			gtk_label_set_text(GTK_LABEL(lbDato1),"Código BCD 1");
			gtk_label_set_text(GTK_LABEL(lbDato2),"Código BCD 2");
			
			break;
		default:
			// Cambio de visual on/off
			gtk_widget_set_visible(txtDato1,FALSE);
			gtk_widget_set_visible(txtDato2,FALSE);
			gtk_widget_set_visible(lbDato2,FALSE);
			gtk_widget_set_visible(lbDato1,FALSE);
			gtk_widget_set_visible(lbDesc,TRUE);		
	}
}

static void RecDato(GtkWidget *widget, gpointer data){	
	Dato1 = g_string_assign(Dato1,gtk_entry_get_text(GTK_ENTRY(txtDato1)));
}
static void RecDato2(GtkWidget *widget, gpointer data){	
	Dato2 = g_string_assign(Dato2,gtk_entry_get_text(GTK_ENTRY(txtDato2)));
}

static void activate_win(GtkApplication *app, gpointer user_data){
	GtkWidget *main_box,*btnBox, *btnCalc, *frame,*fixed;
	
	Dato1 = g_string_new("");
	Dato2 = g_string_new("");
	
    // Creando el contenedor y agregandolo al windows
	main_box = gtk_box_new(TRUE,5);
	fixed = gtk_fixed_new();	
	frame = gtk_frame_new("Resultados");
    
    // Creando el combo  de opciones
    cmbOpc = gtk_combo_box_text_new();
    for (int i = 0; i < G_N_ELEMENTS(Opciones); i++){
		gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(cmbOpc), Opciones[i]);
	}
	gtk_combo_box_set_active (GTK_COMBO_BOX (cmbOpc), 0);
    
    // Creando los cuadro de textos
    txtDato1 = gtk_entry_new();
    txtDato2 = gtk_entry_new();
    lbDesc = gtk_label_new("Programa convertidor de números Binarios,\nGray y Hamming,detección de errores en códigos\nHamming y suma de números BCD.");
    lbDato1 = gtk_label_new("");
    lbDato2 = gtk_label_new("");
    gtk_label_set_justify(GTK_LABEL(lbDesc),GTK_JUSTIFY_CENTER);    

    // Señales
    g_signal_connect(txtDato1,"activate",G_CALLBACK(calcular),NULL);
    g_signal_connect(txtDato2,"activate",G_CALLBACK(calcular),NULL);
    g_signal_connect(cmbOpc,"changed",G_CALLBACK(change_layout),NULL);
    
    // Añadiendo componentes al contenedor principal fixed.
    gtk_fixed_put(GTK_FIXED(fixed),cmbOpc, 100, 10);
    gtk_fixed_put(GTK_FIXED(fixed),lbDesc, 25, 60);
    gtk_fixed_put(GTK_FIXED(fixed),lbDato1, 110, 60);
    gtk_fixed_put(GTK_FIXED(fixed),txtDato1, 110, 80);
    gtk_fixed_put(GTK_FIXED(fixed),lbDato2, 110, 120);
    gtk_fixed_put(GTK_FIXED(fixed),txtDato2, 110, 140);
    
    // Agregando el fixed y el frame al box.
    gtk_box_pack_start(GTK_BOX(main_box), fixed,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(main_box), frame,TRUE,TRUE,0);
    
    
    // Crea la ventana
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Convertidor de números Gray y Hamming");
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 350);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    // Añade el contenedor fixed a la ventana
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // Mostrar todos los componentes
    gtk_widget_show_all(window);
    
    // Mostrando layout principal
    gtk_widget_set_visible(lbDato1,FALSE);
    gtk_widget_set_visible(lbDato2,FALSE);
    gtk_widget_set_visible(txtDato1,FALSE);
    gtk_widget_set_visible(txtDato2,FALSE);
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
