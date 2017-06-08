/*
 *  phukdlib for Arduino Leonardo
 *
 *  Based on Irongeek's PHUKD Library ver 0.4
 *
 *  http://sanchezpano.info
 *
 *  Version:		0.1
 *  Design:		Ernesto Sanchez
 *  Implementation:	Ernesto Sanchez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Arduino.h"
#include "Keyboard.h"
#include "phukdlib_leonardo.h"

/********************************************************************
 * Opens the run bar and executes the command. 
 ********************************************************************/
void CommandAtRunBarMSWIN(char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

/********************************************************************
 * Opens the run bar and executes the command. 
 ********************************************************************/
void CommandAtRunBarGnome(char *SomeCommand){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

/********************************************************************
 * Opens spotlight and executes the command. -Adam Baldwin
 ********************************************************************/
void CommandAtRunBarOSX(char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll(); 
}

/********************************************************************
 * Opens New Terminal and executes command. -Adam Baldwin
 ********************************************************************/
void CommandAtNewTerminal(char *SomeCommand){
  CommandAtRunBarOSX("Terminal");
/*
  // Open a new terminal in case another one was open
  delay(1000);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_N);
  Keyboard.send_now(); // send strokes
  Keyboard.set_modifier(0); //prep release of  control keys
  Keyboard.set_key1(0); //have to do this to keep it from hitting key multiple times.
  Keyboard.send_now(); //Send the key changes
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.set_key1(KEY_ENTER); 
  Keyboard.send_now();    
  Keyboard.set_key1(0);
*/
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('n');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll(); 
}

/********************************************************************
 * Opens the run bar and executes the command. -Aaron Howell
 ********************************************************************/
void ShrinkCurWinOSX(){
/*
  Keyboard.set_modifier(MODIFIERKEY_GUI); //clover key
  Keyboard.set_key1(KEY_H); // clover-h hides window, clover-m minimizes window
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
*/
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('h');
  delay(100);
  Keyboard.releaseAll();
  delay(250);
}

/********************************************************************
 * Shrinks the active window to help hide it.
 ********************************************************************/
void ShrinkCurWin(){
/*
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now(); 
  delay(250);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();  
  Keyboard.print("n");
*/
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(250);
  Keyboard.print("n");
}

void ShrinkCurWinMSWIN(){
  ShrinkCurWin();
}

void ShrinkCurWinGnome(){
  ShrinkCurWin();
}

/********************************************************************
 * This function simplifies the pressing and releasing of a key.  
 ********************************************************************/
void PressAndRelease(int KeyCode,int KeyCount){
  int KeyCounter=0;
  for (KeyCounter=0;  KeyCounter!=KeyCount; KeyCounter++){
/*
    Keyboard.set_key1(KeyCode); // use r key
    Keyboard.send_now(); // send strokes
    Keyboard.set_key1(0); 
    Keyboard.send_now(); // send strokes
*/
    Keyboard.print(KeyCode);
  }
}

/*********************************************************************
 * ledkeys returns the setting of the "lock keys"
 * Num Lock = 1
 * CAPS Lock = 2
 * Scroll Lock = 4
 * Add them together to get combos, for example if all three are on, 7 would be the result
 *********************************************************************/
/*
int ledkeys(void)
{
  return int(keyboard_leds);
}
*/

/*********************************************************************
 * Returns TRUE if NUM Lock LED is on and FALSE otherwise. 
 *********************************************************************/
/*
boolean IsNumbOn(void)
{
  if ((ledkeys() & 1) == 1){
    return true;
  } 
  else {
    return false;
  }      
}
*/

/*********************************************************************
 * Returns TRUE if Caps Lock LED is on and FALSE otherwise. 
 **********************************************************************/
/*
boolean IsCapsOn(void)
{
  if ((ledkeys() & 2) == 2){
    return true;
  } 
  else {
    return false;
  }      
}
*/

/*********************************************************************
 * Returns TRUE if Scroll Lock LED is on and FALSE otherwise. 
 **********************************************************************/
/*
boolean IsScrlOn(void)
{
  if ((ledkeys() & 4) == 4){    
    return true;
  } 
  else {
    return false;
  }      
}
*/
//********************************************************************
