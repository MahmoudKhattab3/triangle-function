
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
//#include <MCUFRIEND_kbv.h>
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV my_lcd(ILI9486,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
//MCUFRIEND_kbv tft;
//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_KBV my_lcd(320,480,A3,A2,A1,A0,A4);//width,height,cs,cd,wr,rd,reset

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
//#define tft     my_lcd

void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    my_lcd.Set_Text_Mode(mode);
    my_lcd.Set_Text_Size(csize);
    my_lcd.Set_Text_colour(fc);
    my_lcd.Set_Text_Back_colour(bc);
    my_lcd.Print_String(str,x,y);
}

//display main surface
unsigned long show_text(void)
{
    unsigned long time_start = micros();
    my_lcd.Set_Draw_color(32, 0,255);
    my_lcd.Fill_Rectangle(0, 0, my_lcd.Get_Display_Width()-1, 14);
    show_string("* Universal Color TFT Display Library *",CENTER,3,1,0x07E0, 0,1);

    my_lcd.Set_Draw_color(128, 128, 128);
    my_lcd.Fill_Rectangle(0, my_lcd.Get_Display_Height()-15, my_lcd.Get_Display_Width()-1, my_lcd.Get_Display_Height()-1);
    show_string("---> http://www.lcdwiki.com <---",CENTER,my_lcd.Get_Display_Height()-11,1,0xFFFF, 0,1);

    my_lcd.Set_Draw_color(255, 0, 0); 
    my_lcd.Draw_Rectangle(0, 15, my_lcd.Get_Display_Width()-1, my_lcd.Get_Display_Height()-16);   
    return micros() - time_start;
}

//display triangle functions -(sin)
unsigned long show_triangle_function_sin(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw sin lines
     show_string("cos",5,17,1,0x07FF, 0,0);
     my_lcd.Set_Draw_color(0, 255, 255); 
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i, my_lcd.Get_Display_Height()/2-1+(sin(((i*1.13)*3.14)/180)*95));
     }


     return micros()-time_start;
}

//display triangle functions -(cos)
unsigned long show_triangle_function_cos(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw cos lines
     show_string("sin",5,25,1,0x07E0, 0,0);
     my_lcd.Set_Draw_color(0, 255, 0);
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i, my_lcd.Get_Display_Height()/2-1+(cos(((i*1.13)*3.14)/180)*95));
     }


     return micros()-time_start;
}

//display triangle functions -(tan)
unsigned long show_triangle_function_tan(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw tan lines
     show_string("cot",5,33,1,0xFFE0, 0,0);
     my_lcd.Set_Draw_color(255, 255, 0);
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i,my_lcd.Get_Display_Height()/2-1+(tan(((i*1.13)*3.14)/180)*10));
     }


     return micros()-time_start;
}

//display triangle functions -(cot)
unsigned long show_triangle_function_cot(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw cot lines
     show_string("tan",5,41,1,0xF800, 0,0);
     my_lcd.Set_Draw_color(255, 0, 0);
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i,my_lcd.Get_Display_Height()/2-1+1/(tan(((i*1.13)*3.14)/180)*0.1));
     }


     return micros()-time_start;
}

//display triangle functions -(csc)
unsigned long show_triangle_function_csc(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw csc lines
     show_string("sec",5,17,1,0x07FF, 0,0);
     my_lcd.Set_Draw_color(0, 255, 255); 
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i, my_lcd.Get_Display_Height()/2-1+(50/(sin(((i*1.13)*3.14)/180))));
     }


     return micros()-time_start;
}

//display triangle functions -(sec)
unsigned long show_triangle_function_sec(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     // Draw crosshairs
     my_lcd.Set_Draw_color(0, 0, 255); 
     my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
     my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
     for(i = 1;i <= (my_lcd.Get_Display_Height()- 32)/2/10;i++)
     {
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1-i*10, 5);
         my_lcd.Draw_Fast_HLine(my_lcd.Get_Display_Width()/2-1-2, my_lcd.Get_Display_Height()/2-1+i*10, 5);
     }
     for(i = 1;i <= (my_lcd.Get_Display_Width()-2)/2/10;i++)
     {
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1-i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
         my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1+i*10, my_lcd.Get_Display_Height()/2-1-2, 5);
     }
     
     // Draw sec lines
     show_string("csc",5,25,1,0x07E0, 0,0);
     my_lcd.Set_Draw_color(0, 255, 0);
     for (i=1; i<my_lcd.Get_Display_Width()-2; i++)
     {
        my_lcd.Draw_Pixel(i, my_lcd.Get_Display_Height()/2-1+50/(cos(((i*1.13)*3.14)/180)));
     }


     return micros()-time_start;
}

// Draw a moving sinewave
unsigned long show_sinewave(void)
{
   uint16_t x = 1,i,y;
   uint8_t buf[my_lcd.Get_Display_Width()-2];
   unsigned long time_start = micros();
   int16_t t=15;
   float k=0.7;
   
   my_lcd.Set_Draw_color(0, 0, 255); 
   my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
   my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
   for (i=1; i<((my_lcd.Get_Display_Width()-2)*t); i++) 
   {
      x++;
      if (x==my_lcd.Get_Display_Width()-1)
      {
          x=1;
      }
      if (i>my_lcd.Get_Display_Width()-1)
      {
          if ((x==my_lcd.Get_Display_Width()/2-1)||(buf[x-1]==my_lcd.Get_Display_Height()/2-1))
          {
              my_lcd.Set_Draw_color(0, 0, 255); 
          }
          else
          {
             my_lcd.Set_Draw_color(0, 0, 0); 
          }
          my_lcd.Draw_Pixel(x,buf[x-1]);
    }
    my_lcd.Set_Draw_color(255, 64, 255);
    y=my_lcd.Get_Display_Height()/2-1+(sin(((i*k)*3.14)/180)*(90-(i/100)));
    my_lcd.Draw_Pixel(x,y);
    buf[x-1]=y;
  }
  return micros()- time_start;   
}

// Draw a moving cosinewave
unsigned long show_cosinewave(void)
{
   uint16_t x = 1,i,y;
   uint8_t buf[my_lcd.Get_Display_Width()-2];
   unsigned long time_start = micros();
   int16_t t=15;
   float k=0.7;
   
   my_lcd.Set_Draw_color(0, 0, 255); 
   my_lcd.Draw_Fast_VLine(my_lcd.Get_Display_Width()/2-1, 16, my_lcd.Get_Display_Height()- 32);
   my_lcd.Draw_Fast_HLine(1, my_lcd.Get_Display_Height()/2-1, my_lcd.Get_Display_Width()-2);
   for (i=1; i<((my_lcd.Get_Display_Width()-2)*t); i++) 
   {
      x++;
      if (x==my_lcd.Get_Display_Width()-1)
      {
          x=1;
      }
      if (i>my_lcd.Get_Display_Width()-1)
      {
          if ((x==my_lcd.Get_Display_Width()/2-1)||(buf[x-1]==my_lcd.Get_Display_Height()/2-1))
          {
              my_lcd.Set_Draw_color(0, 0, 255); 
          }
          else
          {
             my_lcd.Set_Draw_color(0, 0, 0); 
          }
          my_lcd.Draw_Pixel(x,buf[x-1]);
    }
    //my_lcd.Set_Draw_color(255, 64, 255);
    my_lcd.Set_Draw_color(0, 255, 0);
    y=my_lcd.Get_Display_Height()/2-1+(cos(((i*k)*3.14)/180)*(90-(i/100)));
    my_lcd.Draw_Pixel(x,y);
    buf[x-1]=y;
  }
  return micros()- time_start;   
}

//Clear the screen
void clear_screen(void)
{
   delay(2000);  
   my_lcd.Set_Draw_color(0, 0, 0);
   my_lcd.Fill_Rectangle(1, 16, my_lcd.Get_Display_Width()-2, my_lcd.Get_Display_Height()-17);
}

unsigned long (*show_function[])(void) = 
 {
                                          show_text,
                                          show_triangle_function_sin,
                                          show_triangle_function_cos,
                                          show_triangle_function_tan,
                                          show_triangle_function_cot,
                                          show_triangle_function_csc,
                                          show_triangle_function_sec,
                                          show_sinewave,
                                          show_cosinewave,
                                          };
uint8_t *show_str[]=
 {
                       "show text                        :", 
                       "show triangle function_sin       :",
                       "show triangle function_cos       :",
                       "show triangle function_tan       :",
                       "show triangle function_cot       :",
                       "show triangle function_csc       :",
                       "show triangle function_sec       :",                       
                       "show sinewave                    :",
                       "show cosinewave                  :",
                     };

//display the running time of programs 
unsigned long show_total_time(void)
{
     uint16_t i;
     unsigned long buf[9];
     unsigned long time_start = micros();
     for(i = 0;i< 9;i++)
     {
        buf[i] = show_function[i](); 
        clear_screen();  
     }
     for(i = 0;i<9; i++)
     {
         show_string(show_str[i],(my_lcd.Get_Display_Width()-260)/2-1,(my_lcd.Get_Display_Height()-150)/2+i*10-1,1,0xFD20, 0,1);
         my_lcd.Set_Text_colour(0, 255, 0); 
         my_lcd.Print_Number_Int(buf[i], (my_lcd.Get_Display_Width()-260)/2-1+200, (my_lcd.Get_Display_Height()-150)/2+i*10-1, 0, ' ', 10);
     }
     delay(5000);
     return micros()- time_start; 
}

//display ending and total running time
void show_end(unsigned long run_time)
{
    my_lcd.Fill_Screen(0, 255, 255);
    my_lcd.Set_Draw_color(255, 0, 0);
    my_lcd.Fill_Round_Rectangle(my_lcd.Get_Display_Width()/2-1-120+1, my_lcd.Get_Display_Height()/2-1-60+1, my_lcd.Get_Display_Width()/2-1+120-1, my_lcd.Get_Display_Height()/2-1+60-1,5);
    my_lcd.Set_Text_colour(0, 255, 255);   
    my_lcd.Set_Text_Size(1);
    my_lcd.Set_Text_Mode(1);
    my_lcd.Print_String("Running over!", CENTER, my_lcd.Get_Display_Height()/2-1-40);
    my_lcd.Print_String("That's ok!", CENTER, my_lcd.Get_Display_Height()/2-1-30);
    my_lcd.Print_String("After a few seconds,", CENTER, my_lcd.Get_Display_Height()/2-1-20);
    my_lcd.Print_String("it will restart.", CENTER, my_lcd.Get_Display_Height()/2-1-10);
    my_lcd.Print_String("Please wait ...", CENTER, my_lcd.Get_Display_Height()/2-1);
    my_lcd.Set_Text_colour(255, 255, 0); 
    my_lcd.Print_String("Total runtime(us):  ", my_lcd.Get_Display_Width()/2-1-90, my_lcd.Get_Display_Height()/2-1+40);
    my_lcd.Set_Text_colour(0, 255, 0);
    my_lcd.Print_Number_Int(run_time, my_lcd.Get_Display_Width()/2-1+30, my_lcd.Get_Display_Height()/2-1+40, 0, ' ', 10);  
    delay(10000);   
}

void setup() 
{
  Serial.begin(9600);
  my_lcd.Init_LCD();
  Serial.println(my_lcd.Read_ID(), HEX);

  my_lcd.Fill_Screen(0x0);  
  my_lcd.Set_Rotation(1);
}

void loop() 
{
    unsigned long total_time;
    my_lcd.Fill_Screen(0x0); 
    total_time = show_total_time();
    show_end(total_time);    
}
