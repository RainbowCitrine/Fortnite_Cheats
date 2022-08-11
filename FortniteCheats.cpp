/* 
*
* GPC SCRIPT IN C/C++
*  FORTNITE SCRIPT FOR AIM ASSISTS, AUTO CROUCH, RAPID FIRE, AND MORE TO COME SOON 
*  SCRIPT IS MEANT FOR ZERO BUILD IF SUCCESSFUL I WILL RELEASE A BUILD CHEATS VERSION
* 


Developed By: Noah 
	
			     _.-""""`-._ 
 			    ,' _-""""`-_ `.
 			   / ,'.-'"""`-.`. \
			  | / / ,'"""`. \ \ |
			 | | | | ,'"`. | | | |
			 | | | | |   | | | | |
* *********************************************************** 

*/ 



define FIRE_BTN             = PS4_R2;
define ADS_BTN              = PS4_L2;
define SPRINT_BTN           = PS4_L3;
define PRONE_BTN            = PS4_CIRCLE;
define JUMP_BTN             = PS4_CROSS;
define SWITCHWEAPON_BTN     = PS4_TRIANGLE;
define RELOAD_BTN           = PS4_SQUARE;
define MELEE_BTN            = PS4_R3;
define TACTICAL_BTN         = PS4_L1;
define GRANADE_BTN          = PS4_R1;
define UP                   = PS4_UP;
define RIGHT                = PS4_RIGHT;
define DOWN                 = PS4_DOWN;
define LEFT                 = PS4_LEFT;
define RX                   = PS4_RX;
define RY                   = PS4_RY;
define LX                   = PS4_LX;
define LY                   = PS4_LY;
//===============================================================
//    ADJUSTABLE VARIABLES                                       
//===============================================================
// Index to find Value Name string - switchable in game with left/right in ModEdit
    int adjust_variable_idx;                  
int drop_shot_hold;
int drop_shot_rest;
int VRecoil_1 = 20;
int HRecoil_1 = 0;
int VRecoil_2 = 25;
int HRecoil_2 = 0;
int VRecoil_3 = 30;
int HRecoil_3 = 0;
int AimAssistTime;
int AimAssistSize;
int HeadStep;
int HeadMax;
//---Adjustable Variables Count                          
define AMOUNT_OF_VALNAME_IDX = 11; 
//===============================================================
//    MODS TOGGLE VARIABLES                                      
//===============================================================
// Number of MODS -----------------------------------------------
define MAX_MODS_COUNT = 3;                          
// Index to find Mod Toggle Variable 
int modName_idx;  
//  MODS Toggles ------------------------------------------------
  int dropshot_onoff = 2 ; 
  int recoil_profiles_onoff = 0 ; 
  int ToggleBattsStickyAim = 0 ; 
  int Head_Assist_onoff = 1 ; 
//===============================================================
//    MODS TEXT TO DISPLAY                                       
//===============================================================
// Mod Name      -   Text to Display
  const string DROPSHOT             = "Drop Shot" ; 
  const string ANTIRECOIL3Profiles  = "AR 3 Profls" ; 
  const string BATTSSTICKYAIM       = "Sticky Aim" ; 
  const string MOD67_2_VARIABLES    = "Head Assist" ; 
// Mod VALUES      -   Text to Display
const string DROPSHOT_HOLD          = "DS Hold" ;
const string DROPSHOT_REST          = "DS Rest" ;
const string VRECOIL_1             = "VRecoil 1" ;
const string HRECOIL_1             = "HRecoil 1" ;
const string VRECOIL_2             = "VRecoil 2" ;
const string HRECOIL_2  = "HRecoil 2" ;
const string VRECOIL_3             = "VRecoil 3" ;
const string HRECOIL_3              = "HRecoil 3" ;
const string AIMASSIST_TIME         = "AA Time";
const string AIMASSISTSIZE      = "AA Size" ;
const string EDITVAR_1_MOD67      = "Head Step";
const string EDITVAR_2_MOD67      = "Head Max" ;
//===============================================================
//    TITLE STRING                                               
//===============================================================
const string TITLE = "My Script"; // 11 char max 
const string OFF   = "OFF";    
const string ON    = "ON";   
const string SCRIPT_ONOFF  = "SCRIPT WAS";   
// Constant bytes - Convert numbers array - ASCII_NUM[column number] 
const int8 ASCII_NUM[] =                          
//      0  1  2  3  4  5  6  7  8  9  (column numbers)
      {48,49,50,51,52,53,54,55,56,57};                
                                                   
const string NO_EDIT_VAR1  = "No Edit Variables";//  17 
const string NO_EDIT_VAR2  = "for this MOD";// 12       
const uint8 Options [] = {
  31 , // DROPSHOT # 1
  1 , // ANTIRECOIL3Profiles # 2
  1 , // BATTSSTICKYAIM # 3
  67 // MOD67_2_VARIABLES # 4
};
const uint8 EditVal [] = {
  1 , // DROPSHOT # 1
  2 , // ANTIRECOIL3Profiles # 2
  1 , // BATTSSTICKYAIM # 3
  1 // MOD67_2_VARIABLES # 4
};
const uint8 OptRange [][] = {
  { 0 , 1 }, // DROPSHOT # 1
  { 2 , 7 }, // ANTIRECOIL3Profiles # 2
  { 8 , 9 }, // BATTSSTICKYAIM # 3
  { 10 , 11 }  // MOD67_2_VARIABLES # 4
};
const uint8 Min_Max_Options [][]={ 
  { 0 , 4 }, // DROPSHOT # 1
  { 0 , 1 }, // ANTIRECOIL3Profiles # 2
  { 0 , 1 }, // BATTSSTICKYAIM # 3
  { 0 , 2 }  // MOD67_2_VARIABLES # 4
}; 
       
const string EditVarStr []={ 
"DS Hold", // 1
"DS Rest", // 2
"VRecoil 1", // 3
"HRecoil 1", // 4
"VRecoil 2", // 5
"HRecoil 2", // 6
"VRecoil 3", // 7
"HRecoil 3", // 8
"AA Time", // 9
"AA Size", // 10
"Head Step", // 11
"Head Max"  // 12
};
/////////////////////////////////////////////////////////////////////////////  
define TimeToShowIntroPicture = 30000;
/////////////////////////////////////////////////////////////////////////////  
///   INITIALIZATION BLOCK                                                      
/////////////////////////////////////////////////////////////////////////////   
init {  
dropshot_onoff        = get_pvar(SPVAR_1,1,4,2); 
recoil_profiles_onoff = get_pvar(SPVAR_2,0,1,0); 
ToggleBattsStickyAim  = get_pvar(SPVAR_3,0,1,0); 
Head_Assist_onoff     = get_pvar(SPVAR_4,1,2,1); 
drop_shot_hold    = get_pvar(SPVAR_5, 100,6000, 600);
drop_shot_rest    = get_pvar(SPVAR_6, 100,6000, 5000);
VRecoil_1          = get_pvar(SPVAR_7, 1,100, 20);
HRecoil_1          = get_pvar(SPVAR_8,-99,99, 0);
VRecoil_2          = get_pvar(SPVAR_9, 1,99, 25);
HRecoil_2          = get_pvar(SPVAR_10,-99,99, 0);
VRecoil_3          = get_pvar(SPVAR_11, 1,99, 30);
HRecoil_3          = get_pvar(SPVAR_12,-99,99, 0);
AimAssistTime     = get_pvar(SPVAR_13, 1,100, 20);
AimAssistSize     = get_pvar(SPVAR_14, 1,100, 20);
HeadStep          = get_pvar(SPVAR_15, 1,100,2 );
HeadMax           = get_pvar(SPVAR_16, 1,100,30);
}// end of init block
///////////////////////////////////////////////////////////////////////////// 
///   MAIN BLOCK                                                             
/////////////////////////////////////////////////////////////////////////////
main {//---------------------------------
                                  
   /////////////////////////////////////////
 if(get_ival(ADS_BTN)){
     if(event_press(PS4_SHARE)){
         EntireScript_OnOff    = !EntireScript_OnOff;
         blinck(EntireScript_OnOff);
         cls_oled(0);
         draw_rectangle();
         //display_mod(f_idx, f_string, mod_name, f_toggle, f_option)
         display_mod( center_x(sizeof(SCRIPT_ONOFF)- 1, OLED_FONT_MEDIUM_WIDTH) ,SCRIPT_ONOFF [0],EntireScript_OnOff ,1);
         show_mesage_time = 2000;
 		 //--- Set Virtual Machine Speed to Default if script is OFF    
 		 if(!EntireScript_OnOff) set_Virtual_Machine_Speed(VM_Default); 
     }
 }
                          
 if(show_mesage_time){
     show_mesage_time -= get_rtime();
     if(show_mesage_time <= 0) {
         cls_oled(0);    
     }
 }
                               
//============================================================
// KILL SWITCH FOR ENTIRE SCRIPT
//============================================================
 if(EntireScript_OnOff){
  //--- Set Virtual Machine Speed to Default for MENU                     
	if(ModEdit || ModMenu) set_Virtual_Machine_Speed(VM_Default);
    if(display_EDIT){                
    	  // Clear OLED screen         
        cls_oled(0);                        
       // display_edit(f_idx, f_string, f_print, f_val) 
		if(EditVal[ modName_idx ] == 0 ){  
			  //--- print label                
		    line_oled(1,45,127,45,1,0);    
		    print( center_x( 17, OLED_FONT_SMALL_WIDTH ), 20, OLED_FONT_SMALL, 1, NO_EDIT_VAR1[0] ); 
		    print( center_x( 12, OLED_FONT_SMALL_WIDTH ), 33, OLED_FONT_SMALL, 1, NO_EDIT_VAR2[0] ); 
		}                                                                                            
		else {//----  ELSE BEGIN --------------  
          display_edit( adjust_variable_idx [adjust_variable_idx + 1]);
          adjust_variable_idx [adjust_variable_idx + 1] = edit_val(adjust_variable_idx [adjust_variable_idx + 1] );
		}//--- ELSE END   ----------- 
   }//  end of display edit  
    if(refresh_OLED)
    { 
        // Clear OLED screen 
        cls_oled(0);       
                           
        // Draw Rectangle 
        draw_rectangle(); 
        // Display Mod Name and togle status  : ON/OFF   
        if(modName_idx == 0)display_mod( center_x(sizeof(DROPSHOT)- 1, OLED_FONT_MEDIUM_WIDTH) ,DROPSHOT[0],dropshot_onoff,Options[ modName_idx ]);
        if(modName_idx == 1)display_mod( center_x(sizeof(ANTIRECOIL3Profiles)- 1, OLED_FONT_MEDIUM_WIDTH) ,ANTIRECOIL3Profiles[0],recoil_profiles_onoff,Options[ modName_idx ]);
        if(modName_idx == 2)display_mod( center_x(sizeof(BATTSSTICKYAIM)- 1, OLED_FONT_MEDIUM_WIDTH) ,BATTSSTICKYAIM[0],ToggleBattsStickyAim,Options[ modName_idx ]);
        if(modName_idx == 3)display_mod( center_x(sizeof(MOD67_2_VARIABLES)- 1, OLED_FONT_MEDIUM_WIDTH) ,MOD67_2_VARIABLES[0],Head_Assist_onoff,Options[ modName_idx ]);
              
         refresh_OLED = FALSE; 
    } 
    if(display_title){           
          // clear OLED screen    
    	     cls_oled(0);            
    	     print(center_x(sizeof(TITLE) - 1, OLED_FONT_MEDIUM_WIDTH),13,OLED_FONT_MEDIUM,OLED_WHITE,TITLE[0]);
	         //print(center_x(sizeof(TITLE) - 1, OLED_FONT_SMALL_WIDTH),13,OLED_FONT_SMALL,OLED_WHITE,TITLE[0]);
           // screen saver          
	         ModMenu = FALSE;   
           display_title = FALSE;  
           display_black = TRUE;
                                   
    }                            
      
    //-----------------------------
    // Screen saver (OLED off)   
    if(display_black )         
    {                            
        count_black += get_rtime();
        if(count_black >= TimeToShowIntroPicture)   
        {                        
            cls_oled(0);         
            count_black = 0;      
            display_black = FALSE; 
        }                         
    }                           
                                
   /////////////////////////////////////////////////////////
   // MENU EDIT VALUES             
   if(ModEdit){ 
        block_all_inputs(); 
        if(MenuTimeOut){
            CheckIfBtnIsPressed();
        } 
       //--- Exit from EDIT MENU  
       if(event_release(PS4_CIRCLE)){
             ModEdit      = FALSE;           
             display_EDIT = FALSE;           
             ModMenu      = TRUE;            
             refresh_OLED = TRUE;   // display MODS 
       }                    
        ////////////////////////////////////////////////////////////////////////////////  
        //  GO FORWARD                                                                      
        if(!get_ival(ADS_BTN) && event_press(PS4_DOWN)){            
                                          
        	   adjust_variable_idx ++;                 
        	   if(adjust_variable_idx > OptRange[ modName_idx ][ 1 ])  adjust_variable_idx = OptRange[ modName_idx ][ 1 ]; 
             refresh_OLED = FALSE;      
             display_EDIT = TRUE;        
        }          
        ///////////////////////////////////////////////////////////////////////////////  
        //  GO BACK                                                                      
        if(!get_ival(ADS_BTN) && event_press(PS4_UP)){  
                                                               
        	   adjust_variable_idx --;                                      
        	   if(adjust_variable_idx < OptRange[ modName_idx ][ 0 ]) adjust_variable_idx = OptRange[ modName_idx ][ 0 ];
             refresh_OLED = FALSE;      
             display_EDIT = TRUE;        
        }                                                           
            /////////////////////////////////////////////////////// 
        if(MenuTimeOut){
            CheckIfBtnIsPressed();
        }
   }// end of EDIT MENU    
   /////////////////////////////////////////////////////////
   // EDIT MENU ON/OFF            
   if(get_ival(ADS_BTN) && event_press(PS4_OPTIONS)){  
        ModMenu = TRUE;  
        // toggle EditMenu ON/OFF                      
                 modName_idx  = 0;                   
                 refresh_OLED = TRUE;   // display Title    
                 display_EDIT = FALSE;        
                 MenuTimeOut  = menu_time_active;
   }      
   /////////////////////////////////////////////////////////
   // MENU SYSTEM              
   if(ModMenu){  
        block_all_inputs(); 
      //--- Exit from MENU  
      if(event_press(PS4_CIRCLE)){
          ModMenu = FALSE;                     
          ModEdit = FALSE;              
          combo_run(MESSAGE);             
      }                    
      //--- Enter in EDIT MENU 
      if(event_press(PS4_CROSS)){
          ModMenu             = FALSE;   
          adjust_variable_idx = OptRange[ modName_idx ][ 0 ]; 
          ModEdit             = TRUE;   
          display_EDIT        = TRUE; 
      }                    
                                  
        //Display MOD NAME and togle status 
        // Switch MODs                     
        if( !get_ival(ADS_BTN) && event_press(PS4_DOWN)){ 
                                          
        	   modName_idx ++;                 
        	   if(modName_idx > MAX_MODS_COUNT) modName_idx = 0; 
             //////////////////////////////////////
        	   blinck( modName_idx[modName_idx + 1]); 
             //////////////////////////////////////
        }                          
        if(!get_ival(ADS_BTN) && event_press(PS4_UP)){  
                                                               
        	  modName_idx --;                                      
        	  if(modName_idx < 0) modName_idx = MAX_MODS_COUNT;
             //////////////////////////////////////
        	   blinck( modName_idx[modName_idx + 1]); 
             //////////////////////////////////////
          }                        
        	//////////////////////////
                                  
                                  
        // screen saver           
        display_black = FALSE;    
        display_title = FALSE;    
        //////////////////////////////  
        // display mod name and Toggle ON/OFF | Scroll Options 
        if(!get_ival(ADS_BTN) ){    
             if(event_press(PS4_RIGHT)){ //   go back
                 modName_idx[modName_idx + 1] = f_go_back( modName_idx[modName_idx + 1] ); 
             }// go back 
             if(event_press(PS4_LEFT)){//   go forward
                 modName_idx[modName_idx + 1] = f_go_forward( modName_idx[modName_idx + 1] );
             }// go forward 
       } 
        refresh_OLED = TRUE;   
        set_val(PS4_RIGHT,0); 
        set_val(PS4_LEFT,0); 
        set_val(PS4_UP,0); 
        set_val(PS4_DOWN,0); 
        if(MenuTimeOut){
            CheckIfBtnIsPressed();
        }
    } 
    /////////////////////////////////////////////////////////////
    ///    END OF MENU  /////////////////////////////////////////
    /////////////////////////////////////////////////////////////
//========================================================================================================== 
   if(!ModEdit && !ModMenu){//  code for MODS
             //--- LED COLOR INDICATION        
             combo_run(Blink_MOD_ON);          
			//---HEAD SHOT ASSIST 
			if(Head_Assist_onoff) {
			
				if (get_ival(ADS_BTN) && get_ival(FIRE_BTN) || (Head_Assist_onoff == HeadHipAssist && get_ival(FIRE_BTN))) {
					if (abs(get_ival(RY)) < HeadMax) { 
						Head += HeadStep;
						combo_run(HeadAssist_cmb);
					}	
				}             
				if (!get_ival(FIRE_BTN)) Head = 0;
				
				if (Head >= HeadMax) combo_stop(HeadAssist_cmb);
			}
         //===========================================
         //   DROP SHOT 
         //===========================================
        if(dropshot_onoff  && KS_drop_shot) {     
            if(dropshot_onoff == 1){
                //--- FIRE ONLY
                if(get_ival(FIRE_BTN) && !get_ival(ADS_BTN) ) combo_run(DROP_SHOT_cmb); 
                /////////////////////////////////////////
            }
            if(dropshot_onoff == 2){
                //--- ADS & FIRE
                if(get_ival(FIRE_BTN) && get_ival(ADS_BTN) ) combo_run(DROP_SHOT_cmb); 
                /////////////////////////////////////////
            }
            if(dropshot_onoff == 3){
                //--- ADS ONLY
                if(!get_ival(FIRE_BTN) && get_ival(ADS_BTN) ) combo_run(DROP_SHOT_cmb); 
                /////////////////////////////////////////
            }  
            if(dropshot_onoff == 4){
                //--- On Fire
                if(get_ival(FIRE_BTN) ) combo_run(DROP_SHOT_cmb); 
                /////////////////////////////////////////
            } 
        }                                   
    //===========================================
    //   ANTI RECOIL 3 PROFILES 
    //===========================================
//===============================================
//                 ANTI RECOIL PROFILES          
//===============================================
                                                 
	// PROFILE # 1  --------------------------     
	// ---------------------------------------     
	if( get_ival(PS4_L2) && event_press(PS4_UP))  { 
    	switch_profiles (1, 0, 0, 1) ;  
                                                  
		//--- set variables for the Anti Recoil combo to use values from Profile 1
		ANTI_RECOIL       = VRecoil_1;       
		ANTI_RECOIL_H     = HRecoil_1;   
	}                                               
                                                  
	// PROFILE # 2  --------------------------      
	// ---------------------------------------      
	if( get_ival(PS4_L2) && event_press(PS4_RIGHT))  {
		switch_profiles (0, 1, 0, 2) ;  
                                                   
		//--- set variables for the Anti Recoil combo to use values from Profile 2 
		ANTI_RECOIL       = VRecoil_2;        
		ANTI_RECOIL_H     = HRecoil_2;    
	}                                                
                                                   
	// PROFILE # 3  --------------------------       
	// ---------------------------------------       
	if( get_ival(PS4_L2) && event_press(PS4_DOWN))  { 
    	switch_profiles (0, 0, 1, 3) ; 
                                                   
		//--- set variables for the Anti Recoil combo to use values from Profile 3
		ANTI_RECOIL       = VRecoil_3;        
		ANTI_RECOIL_H     = HRecoil_3;    
	}                                                
	// ALL PROFILES OFF WILL TURN ANTI RECOIL OFF    
	// ---------------------------------------       
	if( get_ival(PS4_L2) && event_press(PS4_LEFT))  { 
		switch_profiles (0, 0, 0, 4) ;   
                                                   
		//--- set variables for the Anti Recoil combo to zero
		ANTI_RECOIL       = 0;        
		ANTI_RECOIL_H     = 0;    
	}                                                
	//----  Set Values for Profile 1                 
	if(profile_1_on && recoil_profiles_onoff){                                 
        // hold RS/R3 + UP/DOWN (Vertical Recoil) or LEFT/RIGHT(Horizontal Recoil) 
		if(get_ival(PS4_R3)){                              
            if(event_press(XB1_UP)) {
                VRecoil_1 +=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_1)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_1[0],VRecoil_1[0]);
            }
            if(event_press(XB1_DOWN)){
                VRecoil_1 -=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_1)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_1[0],VRecoil_1[0]);
            }
            //horizontal------------------------------------   
            if(event_press(XB1_LEFT)){
                HRecoil_1     -=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_1)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_1[0],HRecoil_1[0]);
            }
            if(event_press(XB1_RIGHT)){
                HRecoil_1     +=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_1)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_1[0],HRecoil_1[0]);
            }
		}// get RS        
                                                     
		                                       
		ANTI_RECOIL       = VRecoil_1;         
		ANTI_RECOIL_H     = HRecoil_1;     
	}                                                  
	//----  Set Values for Profile 2                 
	if(profile_2_on && recoil_profiles_onoff){                                 
         // hold RS/R3 + UP/DOWN (Vertical Recoil) or LEFT/RIGHT(Horizontal Recoil) 
		     if(get_ival(PS4_R3)){                              
            if(event_press(XB1_UP)) {
                VRecoil_2 +=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_2)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_2[0],VRecoil_2[0]);
            }
            if(event_press(XB1_DOWN)){
                VRecoil_2 -=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_2)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_2[0],VRecoil_2[0]);
            }
            //horizontal------------------------------------   
            if(event_press(XB1_LEFT)){
                HRecoil_2     -=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_2)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_2[0],HRecoil_2[0]);
            }
            if(event_press(XB1_RIGHT)){
                HRecoil_2     +=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_2)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_2[0],HRecoil_2[0]);
            }
        }                             
                                       
		                                   
		ANTI_RECOIL       = VRecoil_2;         
		ANTI_RECOIL_H     = HRecoil_2;     
	}                                                  
	//----  Set Values for Profile 3                 
	if(profile_3_on && recoil_profiles_onoff){                                 
        // hold RS/R3 + UP/DOWN (Vertical Recoil) or LEFT/RIGHT(Horizontal Recoil) 
		    if(get_ival(PS4_R3)){                              
            if(event_press(XB1_UP)) {
                VRecoil_3 +=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_3)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_3[0],VRecoil_3[0]);
            }
            if(event_press(XB1_DOWN)){
                VRecoil_3 -=1;
                on_the_fly_display(center_x(sizeof(VRECOIL_3)- 1,OLED_FONT_MEDIUM_WIDTH),VRECOIL_3[0],VRecoil_3[0]);
            }
            //horizontal------------------------------------   
            if(event_press(XB1_LEFT)){
                HRecoil_3     -=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_3)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_3[0],HRecoil_3[0]);
            }
            if(event_press(XB1_RIGHT)){
                HRecoil_3     +=1;
                on_the_fly_display(center_x(sizeof(HRECOIL_3)- 1,OLED_FONT_MEDIUM_WIDTH),HRECOIL_3[0],HRecoil_3[0]);
            }
        }                             
                                        
	                                     
		ANTI_RECOIL       = VRecoil_3;      
		ANTI_RECOIL_H     = HRecoil_3;     
	}                                                  
                           
//=============================================== 
//                 ANTI RECOIL                    
//=============================================== 
                                                  
//=============================================== 
//               SAVE ANTI RECOIL                    
//=============================================== 
    if(get_ival(PS4_R3)){
        if(event_press(PS4_PS)){
            combo_run(MESSAGE);       
        }
        set_val(PS4_PS,0);
    }

                                                         
    //--------------------------------------------------- 
    if(recoil_profiles_onoff) {                           
                                                             
		if( abs(get_ival(RX)) > AR_Release || abs(get_ival(RY)) > AR_Release) { 
        	combo_stop (AntiRecoil3Profiles);                            
		}                                                       
                                                              
		if( get_ival(ADS_BTN) && get_ival(FIRE_BTN)) {
        	combo_run(AntiRecoil3Profiles);   
		}                 
    }                    
                         
            //--- CLEAR OLED SCREEN after message                                       
            if(time_to_clear_screen){               
                time_to_clear_screen -= get_rtime();
                if(time_to_clear_screen <= 0 ){     
                    QT_MESSAGE_TIMEOUT();     
                }                              
            }            
                          
            //===========================================
            //   Batts Sticky Aim 
            //===========================================
            if(ToggleBattsStickyAim){
                if(get_ival(FIRE_BTN))
                    combo_run(StickyAim);
            }

        } //  end of MODS CODE 
    } //  ENTIRE SCRIPT KILL SWITCH 
} //  end of main block 
///////////////////////////////////////////////////////////////////////////// 
///   COMBO BLOCK                                                             
/////////////////////////////////////////////////////////////////////////////
const int16 ValRange [][] ={
{ 100,6000 }, // drop_shot_hold
{ 100,6000 }, // drop_shot_rest
{ 1,100 }, // VRecoil_1
{ -99,99 }, // HRecoil_1
{ 1,99 }, // VRecoil_2
{ -99,99 }, // HRecoil_2
{ 1,99 }, // VRecoil_3
{ -99,99 }, // HRecoil_3
{ 1,100 }, // AimAssistTime
{ 1,100 }, // AimAssistSize
{ 1,100 }, // HeadStep
{ 1,100 }  // HeadMax
};       
       
//-- VM Speed
define VM_Default = 0;
function set_Virtual_Machine_Speed (f_speed){
    if     (f_speed == 0) vm_tctrl(-0);//10 ms Default
    else if(f_speed == 1) vm_tctrl(-2);// 8 ms
    else if(f_speed == 2) vm_tctrl(-4);// 6 ms
    else if(f_speed == 3) vm_tctrl(-6);// 4 ms
    else if(f_speed == 4) vm_tctrl(-8);// 2 ms
    else if(f_speed == 5) vm_tctrl(-9);// 1 ms
}
           
int primary_weapon = TRUE;
int message_timeout;
int time_to_clear_screen;
function QT_MESSAGE_TIMEOUT (){     
	// Clear OLED Screen              
	cls_oled(0); // will clear oled   
	display_title  = FALSE;           
}                                  
                                      
                       
int exit_wait = 1500;
combo EXIT {     
	wait(exit_wait);     
	cls_oled(0);    
	ModMenu = FALSE;  
	ModEdit = FALSE;    
	display_EDIT = FALSE; 
	display_title = FALSE; 
}                      
int LED_OnOff;       
int rumble_tipe = RUMBLE_A;
       
//=============================================== 
//            LED BLINK                           
//=============================================== 
combo LED_BLINK {                                 
	colourled(LED_OnOff);                           
	wait(200);                                      
	colourled(ColorOFF);                            
	wait(100);                                      
	colourled(LED_OnOff);                           
	wait(200);                                      
	colourled(ColorOFF);                             
	wait(100);                                      
}                                                 
//=============================================== 
//            PROFILE VIBRATE 1 , 2 ,3                           
//=============================================== 
int profile_numbr;                                
combo PROFILES_VIBRATE_NOTIFY {                    
    if(profile_numbr >= 1) set_rumble(rumble_tipe, 100);
    wait(300);                                       
    reset_rumble();                                   
    wait(100);                                       
    if(profile_numbr > 1)set_rumble(rumble_tipe, 100);
    wait(300);                                       
    reset_rumble();                                  
    wait(100);                                       
    if(profile_numbr > 2)set_rumble(rumble_tipe, 100);
    wait(300);                                       
    reset_rumble();                                 
}
define PRIMARY_Profile   = 1;
define SECONDARY_Profile = 2;
function set_profile_notify(f_profile,rumbl_type){
    profile_numbr = f_profile;
    rumble_tipe   = rumbl_type;
    combo_run(PROFILES_VIBRATE_NOTIFY);
}

//=============================================== 
//                 VIBRATE SETUP                 
//=============================================== 
combo vibrate {                                   
	set_rumble(rumble_tipe, 100);                   
	wait(300);                                       
	reset_rumble();                                 
	wait(100);                                       
	set_rumble(rumble_tipe, 100);                   
	wait(300);                                       
	reset_rumble();                                 
}                                                 
//===============================================  
//                 RUMBLE_TIPE                     
//===============================================  
function set_rumble_tipe ( val) {                  
	if( val){ rumble_tipe = RUMBLE_A ; LED_OnOff = Green;}  
	else    { rumble_tipe = RUMBLE_B ; LED_OnOff = Red  ;} 
	combo_run(vibrate);                     
	combo_run(LED_BLINK);                   
}                                         
//===============================================  
//             DOUBLE CLICK 
//===============================================  
int b_dblclick;

function double_click (button) {                      
    if (b_dblclick) {                                 
        b_dblclick -=get_rtime();                                      
    }                                                 
    if (event_press(button) ) {
        if(b_dblclick){
            b_dblclick = 0;
            return TRUE;
        }else{
            b_dblclick = 300;
            return FALSE;
        }
    }                                                 
    return FALSE;                                        
}           

define ColorOFF  = 0;
define Blue      = 1;
define Red       = 2;
define Green     = 3;
define Pink      = 4;
define SkyBlue   = 5;
define Yellow    = 6;
define White     = 7;
                      
data(                 
  0,0,0, //0. ColorOFF
  2,0,0, //1. Blue     
  0,2,0, //2. Red      
  0,0,2, //3. Green    
  2,2,0, //4. Pink     
  2,0,2, //5. SkyBlue 
  0,2,2, //6. Yellow   
  2,2,2  //7. White    
); // end of data segment-------------- 
// COLOR LED function        
//-------------------------------------------------------------- 
                                       
int data_indx;
function colourled(color) {  
    for( data_indx = 0; data_indx < 3; data_indx++ ) {
        set_led(data_indx,duint8 ((color * 3) + data_indx));
    }
}

// Refresh OLED              
    int display_title = TRUE;
    int display_black;      
    int refresh_OLED;        
    int ModMenu;    
    int ModEdit;   
    int display_EDIT;   
    int EntireScript_OnOff = TRUE;// Kill Swith For Entire Script   
    int show_mesage_time; 
////////////////////////////////////// 
/////////////////////////////////////// 
int count_black;                      
int need_to_be_save;                 
int BlinckColor = 3;                 
int Col_ind;                         
combo StickyAim {
	offset_Batts_sticky(PS4_RY,AimAssistSize);
	wait(AimAssistTime);
	offset_Batts_sticky(PS4_RX,AimAssistSize);
	offset_Batts_sticky(PS4_LX,AimAssistSize);
	wait(AimAssistTime);
	offset_Batts_sticky(PS4_RY,inv(AimAssistSize));
	wait(AimAssistTime);
    offset_Batts_sticky(PS4_RX,inv(AimAssistSize));
    offset_Batts_sticky(PS4_LX,inv(AimAssistSize));
    wait(AimAssistTime);
}
function offset_Batts_sticky(Stick,Value) {
  set_val(Stick, clamp(Value * (100 - abs(get_ival(Stick))) / 100 + get_ival(Stick), -100, 100));
  return;
}

//===============================================================
//   MODS COMBO SECTION
//===============================================================
int KS_drop_shot = TRUE; 
combo DROP_SHOT_cmb {                   
    set_val(PRONE_BTN, 100); 
    wait(drop_shot_hold);  
    wait(drop_shot_rest); 
} 
define HeadAssist      = 1;                          
define HeadHipAssist   = 2;  
int Head;
combo HeadAssist_cmb{
	set_val(RY,inv(Head) + get_ival(RY));
}

// ANTI RECOIL VARIABLES  
int ANTI_RECOIL       =  0; //Set this value to compensate for the recoil vertical (0 to 100)  
int ANTI_RECOIL_H     =  0; //Set this value to compensate for the recoil horizontal (-100 to  +100)  
int AR_Release        = 40; // change this value to determine when antirecoil stops working (min: antirecoil value + 10)  
int anti_recoil;  
int antirecoil_h ;
int profile_1_on ;
int profile_2_on ;
int profile_3_on ;
int Scope_only  = TRUE; // TRUE  Antirecoil  ON with Ads+FIRE - FALSE If Antirecoil Always ON
int Invert            =  1; //  
//=============================================== 
//         ANTIRECOIL 3 PROFILES                  
//=============================================== 
combo AntiRecoil3Profiles {                                
   //--- vertical_recoil                           
     anti_recoil = get_ival(RY) + (ANTI_RECOIL * Invert);
     if(anti_recoil > 100) anti_recoil = 100;       
     set_val(RY, anti_recoil);                     
                                                    
   //--- Horizontal_Recoil                          
                                                    
     antirecoil_h = get_ival(RX) + (ANTI_RECOIL_H );
	if(antirecoil_h >100) antirecoil_h=100;           
	else if(antirecoil_h < -100) antirecoil_h= -100;  
	set_val(RX,antirecoil_h);                       
}                                                  
                                    
const string Profile1  = "Profile 1";
const string Profile2  = "Profile 2";
const string Profile3  = "Profile 3";
const string Profile4  = "ALL PROFLS";
const string QT_ON     = "ON";
const string QT_OFF    = "OFF";
                               
function print_QT (f_cheract_size ,  f_label ){   
     rect_oled(1,1,127,63,0,1);                   
     line_oled(1,20,127,20,1,1);                   
	 print( center_x( f_cheract_size , OLED_FONT_MEDIUM_WIDTH)    , 2 , OLED_FONT_MEDIUM , OLED_WHITE, f_label);   
}                                                
function display_Add_QT(togg_number){  
                                            
 	// Clear OLED Screen                          
    cls_oled(0); // will clear oled                  
    if( togg_number == 1){//----PROFILE 1  
    	  print_QT( sizeof(Profile1 ) , Profile1[0] );// PROFILE 1 
    		    print( 53 ,30 , OLED_FONT_LARGE , OLED_WHITE , QT_ON[0] );// Profile 1 ON 
    }                                                                                   
    if( togg_number == 2){//----PROFILE 2                                               
    	  print_QT( sizeof(Profile2 ) , Profile2[0] );// PROFILE  2                        
    		    print( 53 ,30 , OLED_FONT_LARGE , OLED_WHITE , QT_ON[0] );// PROFILE 2 ON  
    }                       
    if( togg_number == 3){//----PROFILE 3                                               
    	  print_QT( sizeof(Profile3 ) , Profile3[0] );// PROFILE  3                        
    		    print( 53 ,30 , OLED_FONT_LARGE , OLED_WHITE , QT_ON[0] );// PROFILE 3 ON  
    }                       
    if( togg_number == 4){//----ALL PROFILES                                               
    	  print_QT( sizeof(Profile4 ) , Profile4[0] );// ALL PROFILES                        
    		print( 47 ,30 , OLED_FONT_LARGE , OLED_WHITE , QT_OFF[0] );//ALL PROFILES OFF 
    }                       
 	   time_to_clear_screen = 500;  
  }                   
function switch_profiles (prf1, prf2, prf3, qt_message){
    if(qt_message == 4 )recoil_profiles_onoff = FALSE;  
    else recoil_profiles_onoff = TRUE;  
    profile_1_on = prf1; // turn Profile 1 ON / OFF    
    profile_2_on = prf2; // turn Profile 2 ON / OFF    
    profile_3_on = prf3; // turn Profile 3 ON / OFF     
    display_Add_QT ( qt_message );    
}

   //=======================================
   //  DISPLAY EDIT VALUE ON THE FLY        
   //=======================================
function on_the_fly_display (f_string, f_print, f_val){
    cls_oled(0);  
    line_oled(1,18,127,18,1,1);
    print(f_string, 0, OLED_FONT_MEDIUM, OLED_WHITE, f_print);  
    number_to_string(f_val, find_digits(f_val));
    time_to_clear_screen  = 2000;
}      
       
define FONT_STATS_INDEX_WIDTH    = 0; 
define FONT_STATS_INDEX_HEIGHT   = 1; 
define FONT_STATS_INDEX_MAXCHARS = 2; 
                                      
                                      
//////////////////////////////////////////////////////////////// 
function horizontal_center_offset(number_characters, font_size) { 
    return (128 - number_characters * FONT_STATS[font_size][FONT_STATS_INDEX_WIDTH]) / 2;
}             
              
const string EXIT_TXT1 = "SETTINGS";  
const string EXIT_TXT2 = "WAS SAVED"; 
                                     
////////////////////////////////////////////////////////////////////////////// 
///  SAVE  
function save_toggles () {  
                    
     set_pvar(SPVAR_1,dropshot_onoff); 
     set_pvar(SPVAR_2,recoil_profiles_onoff); 
     set_pvar(SPVAR_3,ToggleBattsStickyAim); 
     set_pvar(SPVAR_4,Head_Assist_onoff); 
     set_pvar(SPVAR_5,drop_shot_hold); 
     set_pvar(SPVAR_6,drop_shot_rest); 
     set_pvar(SPVAR_7,VRecoil_1); 
     set_pvar(SPVAR_8,HRecoil_1); 
     set_pvar(SPVAR_9,VRecoil_2); 
     set_pvar(SPVAR_10,HRecoil_2); 
     set_pvar(SPVAR_11,VRecoil_3); 
     set_pvar(SPVAR_12,HRecoil_3); 
     set_pvar(SPVAR_13,AimAssistTime); 
     set_pvar(SPVAR_14,AimAssistSize); 
     set_pvar(SPVAR_15,HeadStep); 
     set_pvar(SPVAR_16,HeadMax); 
    combo_run(EXIT);                  
      
}// end of save   
                      
combo MESSAGE {       
    wait(20);         
    save_toggles ();  
    cls_oled(0);      
    print(horizontal_center_offset(sizeof(EXIT_TXT1), OLED_FONT_MEDIUM ), 2, OLED_FONT_MEDIUM, 1, EXIT_TXT1[0]); 
    print(horizontal_center_offset(sizeof(EXIT_TXT2), OLED_FONT_MEDIUM ), 23, OLED_FONT_MEDIUM, 1, EXIT_TXT2[0]);
    exit_wait = 2000;     
}                        
function blinck ( var){  
	if(var){               
		BlinckColor = Green;
	}else{                 
		BlinckColor = Red;    
	}                       
	combo_run(BLINK_NOTIFY); 
}                           
                            
combo BLINK_NOTIFY {        
	colourled(BlinckColor);   
	wait(300);                 
	colourled(ColorOFF);        
	wait(100);                  
	colourled(BlinckColor);      
	wait(300);                   
	colourled(ColorOFF);          
}                                
int MOD_Color;
int blink_n ;
combo Blink_MOD_ON   {
    colourled(ColorOFF);   
    wait(500);                 
    colourled(ColorOFF);   
    wait(1000);
    blink_n +=1; 
    if( blink_n > 0)blink_n = 1; 
}                                
                                
                                
const uint8 FONT_STATS[][] = {  
    {  7, 10, 18 }, // Small    
    { 11, 18, 11 }, // Medium   
    { 16, 26,  7 }  // Large    
};                              
                                
function display_edit(  f_val) {
    print(2, 5, OLED_FONT_SMALL, OLED_WHITE, EditVarStr[adjust_variable_idx]); 
    number_to_string(f_val, find_digits(f_val));     
}       
        
function f_go_forward (f_variable) {
    f_variable       +=1;   
    if(f_variable  > Min_Max_Options[modName_idx][1] )f_variable  = Min_Max_Options[modName_idx][0]; // max option
    need_to_be_save = TRUE;       
    blinck( f_variable );
    return f_variable;
}

function f_go_back (f_variable) {
    f_variable       -=1;   
    if(f_variable  < Min_Max_Options[modName_idx][0] )f_variable  = Min_Max_Options[modName_idx][1]; 
    need_to_be_save = TRUE;       
    blinck( f_variable );
    return f_variable;
}
// Variables for function number_to_string()  
int ssss;                            
int c_c_c,c_val;   
function number_to_string(f_val,f_digits) {                  
//=======================================================
//  number_to_string(value to convert, # of digits in value) 
//                                                           
//  Display Up to Max 16-bit Signed Integer (-32,768 to 32,767) 
//                                                      
//      Convert digits to ASCII                         
//      Add ASCII character to print buffer            
//      Print string centered X & Y on OLED             
//                                                       
//======================================================
    ssss = 1;  c_val = 10000;                            
                                                      
    if(f_val < 0) //--neg numbers                     
    {                                                 
         putc_oled(ssss,45);    //--add leading "-"      
         ssss += 1;                                      
         f_val = abs(f_val);                          
    }                                                 
                                                      
    for(c_c_c = 5; c_c_c >= 1; c_c_c--)                           
    {                                                 
        if(f_digits >= c_c_c)                             
        {                                             
            putc_oled(ssss,ASCII_NUM[f_val / c_val]);    
            f_val = f_val % c_val;                    
            ssss +=  1;                                  
            if(c_c_c == 4)                               
            {                                         
                putc_oled(ssss,44);   //--add ","        
                ssss += 1;                               
            }                                        
        }                                             
        c_val /= 10;                                  
    }                                                
    puts_oled(center_x(ssss - 1,OLED_FONT_LARGE_WIDTH),37,OLED_FONT_LARGE,ssss - 1,OLED_WHITE); // adjustable value centered in X 
}                                                     
int n_str_;                  
int horiz_X_center_sufix;    
                             
function print_number(f_val,f_digits ,print_s_x , print_s_y , f_font) { 
                                                      
    n_str_ = 1;  c_val = 10000;                       
                                                      
    if(f_val < 0) //--neg numbers                     
    {                                                 
         putc_oled(n_str_,45);    //--add leading "-" 
         n_str_ += 1;                                 
         f_val = abs(f_val);                          
                                                      
    }                                                 
                                                      
    for(c_c_c = 5; c_c_c >= 1; c_c_c--)                           
    {                                                 
        if(f_digits >= c_c_c)                             
        {                                              
            putc_oled(n_str_,ASCII_NUM[f_val / c_val]);
            f_val = f_val % c_val;                    
            n_str_ +=  1;                             
                                                      
        }                                             
        c_val /= 10;                                  
    }                                                 
    puts_oled(print_s_x,print_s_y,f_font,n_str_ - 1,OLED_WHITE); // adjustable value centered in X
}                                       
                                                      
                                                      
int f_min, f_max;
function edit_val( f_val ) {  // antirecoil = edit_val( 0 , antirecoil, 99  , 99  ) 
    line_oled(1,18,127,18,1,1);                                        
    f_min = ValRange[adjust_variable_idx][0];                          
    f_max = ValRange[adjust_variable_idx][1];                          
    print_number(f_min ,find_digits(f_min) ,4 , 22 , OLED_FONT_SMALL); 
    // on the right: max value                                         
    print_number(f_max ,find_digits(f_max) ,97 , 22 , OLED_FONT_SMALL);
                                          
    if(get_ival(ADS_BTN)){                  
		if(press_hold(PS4_RIGHT)){            
			f_val ++;                           
			if(f_val > f_max ) f_val = f_max;   
			display_EDIT = TRUE;                
			need_to_be_save = TRUE;             
		}                                     
                                          
		if(press_hold(PS4_LEFT)){             
			f_val --;                           
			if(f_val < f_min ) f_val = f_min;   
			display_EDIT = TRUE;                
			need_to_be_save = TRUE;             
		}                                     
		if(press_hold(PS4_UP)){               
			f_val +=10;                         
			if(f_val > f_max ) f_val = f_max;   
			display_EDIT = TRUE;                
			need_to_be_save = TRUE;             
		}                                     
                                          
		if(press_hold(PS4_DOWN)){             
			f_val -=10;                         
			if(f_val < f_min ) f_val = f_min;   
			display_EDIT = TRUE;                
			need_to_be_save = TRUE;             
		}                                     
	}                                      
    return f_val;                        
}                                        
                                             
                                   
function press_hold(f_btn) {       
//  return TRUE - event_press()    
//- every 250ms when button is held 
	  return event_press(f_btn) || get_ival(f_btn) && get_ptime(f_btn) > 250 
	       && get_ptime(f_btn) % (get_rtime() * 8) == 0;
}               
                
function find_digits(f_num) {                         
//  find_digits(value)                                
//        return Number of Digits in Value Passed     
                                                      
    f_num = abs(f_num);                               
    if(f_num / 10000 > 0) return 5;                   
    if(f_num /  1000 > 0) return 4;                   
    if(f_num /   100 > 0) return 3;                   
    if(f_num /    10 > 0) return 2;                   
                          return 1;                  
}                                                     
///////////////////////////////////////////////
//  FUNCTIONS                                 
                                              
function center_x(f_chars,f_font) {           
//  center_x(number of chars,font size);     
//        return X for Centering String Horizontally 
                                                      
    return (OLED_WIDTH / 2) - ((f_chars * f_font) / 2); 
}                                                      
                                                       
function draw_rectangle()        
{
    line_oled(1,25,127,25,1,1); 
    rect_oled(0, 0,OLED_WIDTH,64,FALSE,1); 
}
const string ModOption_67_0 = "Disable"; 
const string ModOption_67_1 = "Head Assist"; 
const string ModOption_67_2 = "HHip Assist"; 
define ShotModOptions = 31;
define FireModOptions =  9;
const string ModOption_31_0 = "Disable"; 
const string ModOption_31_1 = "Fire Only"; 
const string ModOption_31_2 = "ADS & Fire"; 
const string ModOption_31_3 = "ADS Only"; 
const string ModOption_31_4 = "On Fire"; 
function display_mod( f_string, mod_name, f_toggle, f_option) {   
        // Display MOD_NAME                                    
        print(f_string, 3, OLED_FONT_MEDIUM, OLED_WHITE, mod_name); 
        if(f_option == 1)                              
        {                                                     
        // Display Disable / Enable                                 
            if(f_toggle == 1)                                                             
                print(center_x(sizeof(ON)  - 1, OLED_FONT_LARGE_WIDTH),37,OLED_FONT_LARGE,OLED_WHITE, ON[0]);// Enable 
            else                                                                                               
                print(center_x(sizeof(OFF) - 1, OLED_FONT_LARGE_WIDTH),37,OLED_FONT_LARGE,OLED_WHITE,OFF[0]);// Disable 
        }            
        if(f_option == ShotModOptions)// 31    
        {                                                     
            if(f_toggle == 0)                                                             
                print(center_x(sizeof(ModOption_31_0)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_0[0]);// Disable
                                                                                                                           
            if(f_toggle == 1)                                                             
                print(center_x(sizeof(ModOption_31_1)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_1[0]);// Fire Only
                                                                                                                           
            if(f_toggle == 2)                                                             
                print(center_x(sizeof(ModOption_31_2)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_2[0]);// ADS & Fire
                                                                                                                           
            if(f_toggle == 3)                                                             
                print(center_x(sizeof(ModOption_31_3)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_3[0]);// ADS Only
                                                                                                                           
        }            
        if(f_option == FireModOptions)// 9 FireModOptions   
        {                                                     
            if(f_toggle == 0)                                                             
                print(center_x(sizeof(ModOption_31_0)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_0[0]);// Disable
                                                                                                                           
            if(f_toggle == 1)                                                             
                print(center_x(sizeof(ModOption_31_1)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_1[0]);// Fire Only
                                                                                                                           
            if(f_toggle == 2)                                                             
                print(center_x(sizeof(ModOption_31_2)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_2[0]);// ADS & Fire
                                                                                                                 
            if(f_toggle == 3)                                                             
                print(center_x(sizeof(ModOption_31_4)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_31_4[0]);// On Fire
                                                                                                                 
        }         

        if(f_option == 67)   
        {                                                     
            if(f_toggle == 0)                                                             
                print(center_x(sizeof(ModOption_67_0)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_67_0[0]);// Disable
                                                                                                                           
            if(f_toggle == 1)                                                             
                print(center_x(sizeof(ModOption_67_1)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_67_1[0]);// Head Assist
                                                                                                                           
            if(f_toggle == 2)                                                             
                print(center_x(sizeof(ModOption_67_2)  - 1, OLED_FONT_MEDIUM_WIDTH),37,OLED_FONT_MEDIUM,OLED_WHITE, ModOption_67_2[0]);// HHip Assist
                                                                                                                           
        }            
}//display mod end           
const uint8 MenuButtons [] = {  
  PS4_RIGHT , //0. Up
  PS4_LEFT , //1. Down
  PS4_UP , //2. go back
  PS4_DOWN , //3. go forward
  PS4_CROSS , //4. enter in Edit Menu
  PS4_CIRCLE , //5. exit  Menu
  PS4_OPTIONS , //5. enter in  Menu
  PS4_L2     //6. hold ADS
};//--- End Menu Buttons  

int menu_btn_indx;
int MenuTimeOut;
define menu_time_active = 30000;
function CheckIfBtnIsPressed (){  
    for(menu_btn_indx = 0; menu_btn_indx < 7; menu_btn_indx++){
         if(event_press(MenuButtons[menu_btn_indx]) ){
             MenuTimeOut = menu_time_active;
         }
         if(MenuTimeOut){              
            MenuTimeOut -=1;
            if(MenuTimeOut <= 0 ){    
                ModMenu = FALSE;      
                ModEdit = FALSE;      
                display_EDIT  = FALSE; 
                display_black = TRUE; 
            }
        }
    }
}

function display_MOD_status(f_val,f_size,f_label){  
    if(!ModMenu && !ModEdit){                                           
        // Clear OLED Screen                          
        cls_oled(0); // will clear oled   
        print(f_size, 3, OLED_FONT_MEDIUM ,OLED_WHITE, f_label);   
        if( f_val ){
            print(center_x(sizeof(ON)  - 1, OLED_FONT_LARGE_WIDTH),37,OLED_FONT_LARGE,OLED_WHITE, ON[0]);//MOD is ON
        }
        else{
            print(center_x(sizeof(OFF)  - 1, OLED_FONT_LARGE_WIDTH),37,OLED_FONT_LARGE,OLED_WHITE, OFF[0]);// MOD is OFF
        }    
        time_to_clear_screen = 1500; 
    } 
}


