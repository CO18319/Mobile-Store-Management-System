#include<iostream>
#include<fstream>
#include<gtk/gtk.h>
#include<cstring>
using namespace std;

static int a[4][4];
static GtkWidget* wid[4][4],*window;

class stock
{
 char company[10];
 char model[10];
 int id;
 int num;
 float price;

 public:
 void input();
 void display();
 int check(char *temp);
 int check(int id_tem);	
 int check(float p_tem);
 int check(float p_tem,float p2_tem);
 int buy(char* name,char* temp);
 void change();
};

void stock::input()
 {
   cout<<endl<<"Enter company  : ";
   cin>>company;
   cout<<"Enter Model:";
   cin>>model;
   cout<<"Enter id of mobile : ";
   cin>>id;
   cout<<"Enter number of mobiles :";
   cin>>num;
   cout<<"Enter price : ";
   cin>>price;
   cout<<endl;
 }

void stock::display()
 {
   cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
 }

int stock::check(char *temp)
{

   if (strcmp(model,temp)==0)
   {
     cout<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
     cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
     
   }
   
   else
     return 0;
}

int stock::check(int id_tem)
 {
   if (id==id_tem)
   {
     cout<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
     cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
     return 1;
   }
   
   else
     return 0;
 }

int stock::check(float p_tem)
{
   if (price==p_tem)
   {
     cout<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
     cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
     return 1;
   }
   
   else
     return 0;
}

int stock::check(float p_tem,float p2_tem)
{
  if (price>=p_tem && price<=p2_tem)
   {
     cout<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
     cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
     return 1;
   }
   
   else
     return 0;
}

int stock::buy(char* name,char* temp)
{
    float rs_temp;
    if (strcmp(company,name)==0 && strcmp(model,temp)==0)
    {
      cout<<endl<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
      cout<<setw(10)<<company<<setw(10)<<model<<setw(10)<<id<<setw(10)<<num<<setw(10)<<price<<endl<<endl;
      cout<<"Enter amount Rs."<<price<<endl;
      cin>>rs_temp;
      if(price==rs_temp)
      {
        cout<<"Purchase done"<<endl<<endl;
	return 1;      
      }
      else if(price<rs_temp)
      {
          cout<<endl<<"Balance = Rs."<<rs_temp-price<<"       Purchase Done"<<endl<<endl;
          return 1;
      }
      else
      {
         cout<<"Purchase failed"<<endl<<endl;
         return 0;
      }
   }
}

void stock::change()
{
 num=num-1;
}


stock s[10],st;
int i,m,n,id_temp;
float p_temp,p2_temp;
char checks,temp[10],temp2[10],name[10];

static void button_clicked(GtkWidget* widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);

        int i,n;
        cout<<endl<<"Enter the number of companies for which you want to enter the data"<<endl;
        cin>>n;
        for(i=0;i<n;i++)
        {
          s[i].input();
          file.write((char*)&s[i],sizeof(s[i])); 
        }     
	cout<<endl<<"Stock entered"<<endl;        
	file.clear();
	file.close();
}

static void button2_clicked(GtkWidget *widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);	
	cout<<endl<<"Current Stocks"<<endl<<setw(10)<<"COMPANY"<<setw(10)<<"MODEL"<<setw(10)<<"ID"<<setw(10)<<"NUMBER"<<setw(10)<<"PRICE"<<endl;
        file.seekg(0,ios::beg);
        while(file.read((char*)&st,sizeof(st)))
        {
          st.display();
        }
        file.clear();
	file.close();
}

static void button3_clicked(GtkWidget *widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);	
	cout<<endl<<"Enter model of mobile : ";
         cin>>temp;
         file.seekg(0,ios::beg); 
	 while(file.read((char*)&st,sizeof(st)))
         {
              m=st.check(temp);
              if(m)
                break;
         }

         if(m==0)
             cout<<"No mobile found"<<endl<<endl;
	 file.clear();
	 file.close();
}

static void button4_clicked(GtkWidget *widget,gpointer data)
{
	 fstream file;
	 file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);
 	 cout<<endl<<"Enter price : ";
         cin>>p_temp;
         file.seekg(0,ios::beg); 
         while(file.read((char*)&st,sizeof(st)))
         {
              m=st.check(p_temp);
              if(m)
                  break;
         }
	
	 if(m==0)
             cout<<"No mobile found"<<endl<<endl;
         else
            cout<<endl<<endl;
	 
         file.clear();
	 file.close(); 
}

static void button5_clicked(GtkWidget *widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);	
	cout<<endl<<"Enter id of mobile : ";
         cin>>id_temp;
         file.seekg(0,ios::beg); 
	 while(file.read((char*)&st,sizeof(st)))
         {
              m=st.check(id_temp);
              if(m)
                 break;
         }

         if(m==0)
             cout<<"No mobile found"<<endl<<endl;
	 file.clear();
	 file.close();
}

static void button6_clicked(GtkWidget *widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);	
	cout<<endl<<"Enter price range : ";
        cin>>p_temp>>p2_temp;
        file.seekg(0,ios::beg);
        while(file.read((char*)&st,sizeof(st)))
        {
          m=st.check(p_temp,p2_temp);
        }
      
        file.clear();
	file.close();
}

static void button7_clicked(GtkWidget *widget,gpointer data)
{
	fstream file;
	file.open("stocks.dat",ios::in|ios::ate|ios::out|ios::binary);	
	cout<<endl<<"Enter company : ";
        cin>>name;
        cout<<"Enter model : ";
        cin>>temp2;
        file.seekg(0,ios::beg); 
        int t,x; 
        while(file.read((char*)&st,sizeof(st)))
        {
              m=st.buy(name,temp2);
              if(m==1)
	      {
                 st.change();
                 t=sizeof(st);
                 file.seekg(-t,ios::cur);
                 file.write((char*)&st,sizeof(st));
                 x=1;
              }
              
              if(x==1)
                  break;
        }
        
        if(m==0)
             cout<<"No mobile found"<<endl<<endl;
        else
            cout<<endl<<endl;
	 
        file.clear();
	file.close();
}

static void menu_response(GtkWidget* menu_item,gpointer data)
{
        if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)),"About")==0)
        {
		cout<<endl<<endl;			
		g_print("It is a Mobile Store Mangaement System which helps the user in monitoring and controlling the transactions of mobile"); 			g_print("phones in a Mobile Store. It provides the user to maintain the Mobile Phone details like checking the existing stock");
		g_print(" and entering new stock. It also provides the option for buying a mobile phone which will check the stock and update"); 
		g_print("the data of purchased mobile phone");        
	}

	
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)),"Exit")==0)
        {
                gtk_main_quit();
        }

}

int main(int argc,char* argv[])
{
	const char* file[] = {"About","Exit"};
        gtk_init(&argc,&argv);
        GtkWidget *vbox,*hbox,*separator,*button,*entry,*button2,*button3,*button4,*button5,
	*button6,*button7,*menu_item,*file_menu,*help_menu,*menu_bar,*label;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);        
	vbox=gtk_vbox_new(0,0);
        
        file_menu=gtk_menu_new();
        menu_bar=gtk_menu_bar_new();
        menu_item=gtk_menu_item_new_with_label("File");
     	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);
	
        for(int i=0;i<2;i++)
        {
                menu_item=gtk_menu_item_new_with_label(file[i]);
                gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
                g_signal_connect(menu_item,"activate",G_CALLBACK(menu_response),NULL);
        }
        
	gtk_box_pack_start(GTK_BOX(vbox),menu_bar,0,0,0);

	//button1	
	button=gtk_button_new_with_label("Enter Stock");
        g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),NULL);
	gtk_box_pack_start(GTK_BOX(vbox),button,0,0,0);
	//button2	
	button2=gtk_button_new_with_label("Check Stock");
	g_signal_connect(button2,"clicked",G_CALLBACK(button2_clicked),NULL);
	gtk_box_pack_start(GTK_BOX(vbox),button2,0,0,0);	
	//button3	
	button3=gtk_button_new_with_label("Search mobile by model");
	g_signal_connect(button3,"clicked",G_CALLBACK(button3_clicked),NULL);	
	gtk_box_pack_start(GTK_BOX(vbox),button3,0,0,0);
	//button4	
	button4=gtk_button_new_with_label("Search mobile by price");
	g_signal_connect(button4,"clicked",G_CALLBACK(button4_clicked),NULL);	
	gtk_box_pack_start(GTK_BOX(vbox),button4,0,0,0);		
	//button5
	button5=gtk_button_new_with_label("Search mobile by id");
	g_signal_connect(button5,"clicked",G_CALLBACK(button5_clicked),NULL);
	gtk_box_pack_start(GTK_BOX(vbox),button5,0,0,0);	
	//button6	
	button6=gtk_button_new_with_label("Enter price range");
	g_signal_connect(button6,"clicked",G_CALLBACK(button6_clicked),NULL);	
	gtk_box_pack_start(GTK_BOX(vbox),button6,0,0,0);			
	//button7	
	button7=gtk_button_new_with_label("Buy a mobile");	
	g_signal_connect(button7,"clicked",G_CALLBACK(button7_clicked),NULL);	
	gtk_box_pack_start(GTK_BOX(vbox),button7,0,0,0);

	g_signal_connect(window, "delete_event" , G_CALLBACK(gtk_main_quit),NULL);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_set_size_request(window,590,500);
	gtk_window_set_title(GTK_WINDOW(window),"MOBILE STORE SYSTEM");	
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}	
