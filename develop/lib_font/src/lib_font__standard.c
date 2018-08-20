/*
 *  This file is part of the HanoverFlipDot project 
 *  (https://github.com/EmbeddedAl/HanoverFlipDot).
 *
 *  HanoverFlipDot is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HanoverFlipDot is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HanoverFlipDot. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Creation: 2018-08-09, @EmbeddedAl
 */


/* includes */
#include <stdio.h>
#include <stdint.h>
#include "lib_font__standard.h"

#define LIB_FONT__STANDARD__FONT_HEIGHT 	14

static const uint8_t s_lib_font__standard__Bitmaps[] =
{
	/* @0 ' ' (2 pixels wide) */
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   

	/* @14 '!' (2 pixels wide) */
	0x00, //   
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   

	/* @28 '"' (5 pixels wide) */
	0x00, //      
	0xD8, // ## ##
	0xD8, // ## ##
	0xD8, // ## ##
	0xD8, // ## ##
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      

	/* @42 '#' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x12, //    #  # 
	0x12, //    #  # 
	0x7F, //  #######
	0x7F, //  #######
	0x24, //   #  #  
	0xFE, // ####### 
	0xFE, // ####### 
	0x48, //  #  #   
	0x48, //  #  #   
	0x00, //         
	0x00, //         
	0x00, //         

	/* @56 '$' (7 pixels wide) */
	0x10, //    #   
	0x10, //    #   
	0x7C, //  ##### 
	0xD2, // ## #  #
	0xD0, // ## #   
	0xF0, // ####   
	0x7C, //  ##### 
	0x1E, //    ####
	0x16, //    # ##
	0x96, // #  # ##
	0x7C, //  ##### 
	0x10, //    #   
	0x10, //    #   
	0x00, //        

	/* @70 '%' (15 pixels wide) */
	0x00, 0x00, //                
	0x00, 0x00, //                
	0x78, 0x40, //  ####    #     
	0xCC, 0x40, // ##  ##   #     
	0xCC, 0x80, // ##  ##  #      
	0xCC, 0xBC, // ##  ##  # #### 
	0xCD, 0x66, // ##  ## # ##  ##
	0x7A, 0x66, //  #### #  ##  ##
	0x02, 0x66, //       #  ##  ##
	0x04, 0x66, //      #   ##  ##
	0x04, 0x3C, //      #    #### 
	0x00, 0x00, //                
	0x00, 0x00, //                
	0x00, 0x00, //                

	/* @98 '&' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x78, 0x00, //  ####    
	0xCC, 0x00, // ##  ##   
	0xCC, 0x00, // ##  ##   
	0xCD, 0x80, // ##  ## ##
	0x79, 0x80, //  ####  ##
	0xCD, 0x00, // ##  ## # 
	0xC6, 0x00, // ##   ##  
	0xC7, 0x00, // ##   ### 
	0x79, 0x80, //  ####  ##
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	/* @126 ''' (2 pixels wide) */
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   

	/* @140 '(' (5 pixels wide) */
	0x00, //      
	0x18, //    ##
	0x30, //   ## 
	0x60, //  ##  
	0x60, //  ##  
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0x60, //  ##  
	0x60, //  ##  
	0x30, //   ## 
	0x18, //    ##

	/* @154 ')' (5 pixels wide) */
	0x00, //      
	0xC0, // ##   
	0x60, //  ##  
	0x30, //   ## 
	0x30, //   ## 
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x30, //   ## 
	0x30, //   ## 
	0x60, //  ##  
	0xC0, // ##   

	/* @168 '*' (7 pixels wide) */
	0x00, //        
	0x10, //    #   
	0x92, // #  #  #
	0x54, //  # # # 
	0x38, //   ###  
	0x54, //  # # # 
	0x92, // #  #  #
	0x10, //    #   
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        

	/* @182 '+' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x10, //    #   
	0x10, //    #   
	0x10, //    #   
	0xFE, // #######
	0x10, //    #   
	0x10, //    #   
	0x10, //    #   
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        

	/* @196 ',' (4 pixels wide) */
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x70, //  ###
	0x60, //  ## 
	0x60, //  ## 
	0xC0, // ##  
	0xC0, // ##  

	/* @210 '-' (5 pixels wide) */
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0xF8, // #####
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      

	/* @224 '.' (2 pixels wide) */
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   

	/* @238 '/' (7 pixels wide) */
	0x00, //        
	0x06, //      ##
	0x06, //      ##
	0x0C, //     ## 
	0x0C, //     ## 
	0x18, //    ##  
	0x18, //    ##  
	0x30, //   ##   
	0x30, //   ##   
	0x60, //  ##    
	0x60, //  ##    
	0xC0, // ##     
	0xC0, // ##     
	0x00, //        

	/* @252 '0' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @266 '1' (6 pixels wide) */
	0x00, //       
	0x00, //       
	0x30, //   ##  
	0xF0, // ####  
	0x30, //   ##  
	0x30, //   ##  
	0x30, //   ##  
	0x30, //   ##  
	0x30, //   ##  
	0x30, //   ##  
	0xFC, // ######
	0x00, //       
	0x00, //       
	0x00, //       

	/* @280 '2' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x06, //      ##
	0x0C, //     ## 
	0x18, //    ##  
	0x30, //   ##   
	0x60, //  ##    
	0xFE, // #######
	0x00, //        
	0x00, //        
	0x00, //        

	/* @294 '3' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x06, //      ##
	0x1C, //    ### 
	0x06, //      ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @308 '4' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x0C, //     ##  
	0x1C, //    ###  
	0x2C, //   # ##  
	0x4C, //  #  ##  
	0x8C, // #   ##  
	0xFF, // ########
	0x0C, //     ##  
	0x0C, //     ##  
	0x0C, //     ##  
	0x00, //         
	0x00, //         
	0x00, //         

	/* @322 '5' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7E, //  ######
	0x60, //  ##    
	0x60, //  ##    
	0x7C, //  ##### 
	0x06, //      ##
	0x06, //      ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @336 '6' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x3C, //   #### 
	0x60, //  ##    
	0xC0, // ##     
	0xFC, // ###### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @350 '7' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xFE, // #######
	0x06, //      ##
	0x06, //      ##
	0x0C, //     ## 
	0x0C, //     ## 
	0x18, //    ##  
	0x18, //    ##  
	0x30, //   ##   
	0x30, //   ##   
	0x00, //        
	0x00, //        
	0x00, //        

	/* @364 '8' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @378 '9' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7E, //  ######
	0x06, //      ##
	0x0C, //     ## 
	0x78, //  ####  
	0x00, //        
	0x00, //        
	0x00, //        

	/* @392 ':' (2 pixels wide) */
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   

	/* @406 ';' (4 pixels wide) */
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x60, //  ## 
	0x60, //  ## 
	0x00, //     
	0x00, //     
	0x00, //     
	0x70, //  ###
	0x60, //  ## 
	0x60, //  ## 
	0xC0, // ##  
	0xC0, // ##  

	/* @420 '<' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x01, //        #
	0x06, //      ## 
	0x18, //    ##   
	0x60, //  ##     
	0x80, // #       
	0x60, //  ##     
	0x18, //    ##   
	0x06, //      ## 
	0x01, //        #
	0x00, //         
	0x00, //         
	0x00, //         

	/* @434 '=' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xFE, // #######
	0x00, //        
	0x00, //        
	0xFE, // #######
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        

	/* @448 '>' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x80, // #       
	0x60, //  ##     
	0x18, //    ##   
	0x06, //      ## 
	0x01, //        #
	0x06, //      ## 
	0x18, //    ##   
	0x60, //  ##     
	0x80, // #       
	0x00, //         
	0x00, //         
	0x00, //         

	/* @462 '?' (6 pixels wide) */
	0x00, //       
	0x00, //       
	0x78, //  #### 
	0xCC, // ##  ##
	0x0C, //     ##
	0x18, //    ## 
	0x30, //   ##  
	0x30, //   ##  
	0x00, //       
	0x30, //   ##  
	0x30, //   ##  
	0x00, //       
	0x00, //       
	0x00, //       

	/* @476 '@' (11 pixels wide) */
	0x00, 0x00, //            
	0x00, 0x00, //            
	0x1F, 0x00, //    #####   
	0x60, 0xC0, //  ##     ## 
	0x4F, 0x40, //  #  #### # 
	0x9B, 0x20, // #  ## ##  #
	0x9B, 0x20, // #  ## ##  #
	0x9B, 0x20, // #  ## ##  #
	0x9B, 0x20, // #  ## ##  #
	0x4F, 0xC0, //  #  ###### 
	0x60, 0x00, //  ##        
	0x1F, 0x00, //    #####   
	0x00, 0x00, //            
	0x00, 0x00, //            

	/* @504 'A' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x18, //    ##   
	0x18, //    ##   
	0x3C, //   ####  
	0x3C, //   ####  
	0x66, //  ##  ## 
	0x66, //  ##  ## 
	0xFF, // ########
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x00, //         
	0x00, //         
	0x00, //         

	/* @518 'B' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xFC, // ######  
	0xC6, // ##   ## 
	0xC6, // ##   ## 
	0xC6, // ##   ## 
	0xFE, // ####### 
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xFE, // ####### 
	0x00, //         
	0x00, //         
	0x00, //         

	/* @532 'C' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x3E, //   ##### 
	0x63, //  ##   ##
	0xC3, // ##    ##
	0xC0, // ##      
	0xC0, // ##      
	0xC0, // ##      
	0xC3, // ##    ##
	0x63, //  ##   ##
	0x3E, //   ##### 
	0x00, //         
	0x00, //         
	0x00, //         

	/* @546 'D' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xFC, // ######  
	0xC6, // ##   ## 
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC6, // ##   ## 
	0xFC, // ######  
	0x00, //         
	0x00, //         
	0x00, //         

	/* @560 'E' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xFE, // #######
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xFE, // #######
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xFE, // #######
	0x00, //        
	0x00, //        
	0x00, //        

	/* @574 'F' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xFE, // #######
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xFE, // #######
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0x00, //        
	0x00, //        
	0x00, //        

	/* @588 'G' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x3E, //   ##### 
	0x63, //  ##   ##
	0xC3, // ##    ##
	0xC0, // ##      
	0xC0, // ##      
	0xC7, // ##   ###
	0xC3, // ##    ##
	0x63, //  ##   ##
	0x3F, //   ######
	0x00, //         
	0x00, //         
	0x00, //         

	/* @602 'H' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xFF, 0x80, // #########
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	/* @630 'I' (4 pixels wide) */
	0x00, //     
	0x00, //     
	0xF0, // ####
	0x60, //  ## 
	0x60, //  ## 
	0x60, //  ## 
	0x60, //  ## 
	0x60, //  ## 
	0x60, //  ## 
	0x60, //  ## 
	0xF0, // ####
	0x00, //     
	0x00, //     
	0x00, //     

	/* @644 'J' (6 pixels wide) */
	0x00, //       
	0x00, //       
	0x7C, //  #####
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0xF8, // ##### 
	0x00, //       
	0x00, //       
	0x00, //       

	/* @658 'K' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xC6, // ##   ## 
	0xCC, // ##  ##  
	0xD8, // ## ##   
	0xF0, // ####    
	0xF0, // ####    
	0xD8, // ## ##   
	0xCC, // ##  ##  
	0xC6, // ##   ## 
	0xC3, // ##    ##
	0x00, //         
	0x00, //         
	0x00, //         

	/* @672 'L' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xFE, // #######
	0x00, //        
	0x00, //        
	0x00, //        

	/* @686 'M' (10 pixels wide) */
	0x00, 0x00, //           
	0x00, 0x00, //           
	0xE1, 0xC0, // ###    ###
	0xE1, 0xC0, // ###    ###
	0xB2, 0xC0, // # ##  # ##
	0xB2, 0xC0, // # ##  # ##
	0x9C, 0xC0, // #  ###  ##
	0x9C, 0xC0, // #  ###  ##
	0x88, 0xC0, // #   #   ##
	0x88, 0xC0, // #   #   ##
	0x80, 0xC0, // #       ##
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           

	/* @714 'N' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xE1, // ###    #
	0xE1, // ###    #
	0xB1, // # ##   #
	0xB1, // # ##   #
	0x99, // #  ##  #
	0x8D, // #   ## #
	0x8D, // #   ## #
	0x87, // #    ###
	0x87, // #    ###
	0x00, //         
	0x00, //         
	0x00, //         

	/* @728 'O' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x3E, 0x00, //   #####  
	0x63, 0x00, //  ##   ## 
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0x63, 0x00, //  ##   ## 
	0x3E, 0x00, //   #####  
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          

	/* @756 'P' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xFC, // ###### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFC, // ###### 
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0x00, //        
	0x00, //        
	0x00, //        

	/* @770 'Q' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x3E, 0x00, //   #####  
	0x63, 0x00, //  ##   ## 
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0x63, 0x00, //  ##   ## 
	0x3E, 0x00, //   #####  
	0x06, 0x00, //      ##  
	0x03, 0x80, //       ###
	0x00, 0x00, //          

	/* @798 'R' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xFC, // ######  
	0xC6, // ##   ## 
	0xC6, // ##   ## 
	0xC6, // ##   ## 
	0xFC, // ######  
	0xD8, // ## ##   
	0xCC, // ##  ##  
	0xC6, // ##   ## 
	0xC3, // ##    ##
	0x00, //         
	0x00, //         
	0x00, //         

	/* @812 'S' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xE0, // ###    
	0x7C, //  ##### 
	0x0E, //     ###
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @826 'T' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xFF, // ########
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x00, //         
	0x00, //         
	0x00, //         

	/* @840 'U' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x7E, //  ###### 
	0x00, //         
	0x00, //         
	0x00, //         

	/* @854 'V' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x66, //  ##  ## 
	0x66, //  ##  ## 
	0x3C, //   ####  
	0x3C, //   ####  
	0x18, //    ##   
	0x18, //    ##   
	0x00, //         
	0x00, //         
	0x00, //         

	/* @868 'W' (12 pixels wide) */
	0x00, 0x00, //             
	0x00, 0x00, //             
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0x66, 0x60, //  ##  ##  ## 
	0x6F, 0x60, //  ## #### ## 
	0x69, 0x60, //  ## #  # ## 
	0x39, 0xC0, //   ###  ###  
	0x30, 0xC0, //   ##    ##  
	0x30, 0xC0, //   ##    ##  
	0x00, 0x00, //             
	0x00, 0x00, //             
	0x00, 0x00, //             

	/* @896 'X' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xC3, // ##    ##
	0x66, //  ##  ## 
	0x66, //  ##  ## 
	0x3C, //   ####  
	0x18, //    ##   
	0x3C, //   ####  
	0x66, //  ##  ## 
	0x66, //  ##  ## 
	0xC3, // ##    ##
	0x00, //         
	0x00, //         
	0x00, //         

	/* @910 'Y' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x66, //  ##  ## 
	0x3C, //   ####  
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x18, //    ##   
	0x00, //         
	0x00, //         
	0x00, //         

	/* @924 'Z' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0xFE, // #######
	0x0C, //     ## 
	0x18, //    ##  
	0x18, //    ##  
	0x30, //   ##   
	0x30, //   ##   
	0x60, //  ##    
	0x60, //  ##    
	0xFE, // #######
	0x00, //        
	0x00, //        
	0x00, //        

	/* @938 '[' (4 pixels wide) */
	0x00, //     
	0xF0, // ####
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xC0, // ##  
	0xF0, // ####
	0x00, //     

	/* @952 '\' (7 pixels wide) */
	0x00, //        
	0xC0, // ##     
	0xC0, // ##     
	0x60, //  ##    
	0x60, //  ##    
	0x30, //   ##   
	0x30, //   ##   
	0x18, //    ##  
	0x18, //    ##  
	0x0C, //     ## 
	0x0C, //     ## 
	0x06, //      ##
	0x06, //      ##
	0x00, //        

	/* @966 ']' (4 pixels wide) */
	0x00, //     
	0xF0, // ####
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0xF0, // ####
	0x00, //     

	/* @980 '^' (8 pixels wide) */
	0x00, //         
	0x00, //         
	0x18, //    ##   
	0x3C, //   ####  
	0x66, //  ##  ## 
	0xC3, // ##    ##
	0x00, //         
	0x00, //         
	0x00, //         
	0x00, //         
	0x00, //         
	0x00, //         
	0x00, //         
	0x00, //         

	/* @994 '_' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0xFF, 0x80, // #########
	0x00, 0x00, //          

	/* @1022 '`' (3 pixels wide) */
	0x00, //    
	0xC0, // ## 
	0x60, //  ##
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    

	/* @1036 'a' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0x06, //      ##
	0x7E, //  ######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7E, //  ######
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1050 'b' (7 pixels wide) */
	0x00, //        
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xDC, // ## ### 
	0xE6, // ###  ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFC, // ###### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1064 'c' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1078 'd' (7 pixels wide) */
	0x00, //        
	0x06, //      ##
	0x06, //      ##
	0x06, //      ##
	0x7E, //  ######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xCE, // ##  ###
	0x76, //  ### ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1092 'e' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0xC0, // ##     
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1106 'f' (5 pixels wide) */
	0x00, //      
	0x38, //   ###
	0x60, //  ##  
	0x60, //  ##  
	0xF8, // #####
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x00, //      
	0x00, //      
	0x00, //      

	/* @1120 'g' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7E, //  ######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xCE, // ##  ###
	0x76, //  ### ##
	0x06, //      ##
	0x06, //      ##
	0x7C, //  ##### 

	/* @1134 'h' (7 pixels wide) */
	0x00, //        
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xDC, // ## ### 
	0xE6, // ###  ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1148 'i' (2 pixels wide) */
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   

	/* @1162 'j' (4 pixels wide) */
	0x00, //     
	0x30, //   ##
	0x30, //   ##
	0x00, //     
	0x70, //  ###
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0xE0, // ### 

	/* @1176 'k' (7 pixels wide) */
	0x00, //        
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     
	0xCC, // ##  ## 
	0xD8, // ## ##  
	0xF0, // ####   
	0xF0, // ####   
	0xD8, // ## ##  
	0xCC, // ##  ## 
	0xC6, // ##   ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1190 'l' (2 pixels wide) */
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   

	/* @1204 'm' (12 pixels wide) */
	0x00, 0x00, //             
	0x00, 0x00, //             
	0x00, 0x00, //             
	0x00, 0x00, //             
	0xDC, 0xE0, // ## ###  ### 
	0xE7, 0x30, // ###  ###  ##
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0xC6, 0x30, // ##   ##   ##
	0x00, 0x00, //             
	0x00, 0x00, //             
	0x00, 0x00, //             

	/* @1232 'n' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xDC, // ## ### 
	0xE6, // ###  ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1246 'o' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7C, //  ##### 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7C, //  ##### 
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1260 'p' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xDC, // ## ### 
	0xE6, // ###  ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFC, // ###### 
	0xC0, // ##     
	0xC0, // ##     
	0xC0, // ##     

	/* @1274 'q' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x7E, //  ######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xCE, // ##  ###
	0x76, //  ### ##
	0x06, //      ##
	0x06, //      ##
	0x06, //      ##

	/* @1288 'r' (5 pixels wide) */
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0xD8, // ## ##
	0xF8, // #####
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0xC0, // ##   
	0x00, //      
	0x00, //      
	0x00, //      

	/* @1302 's' (6 pixels wide) */
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0x7C, //  #####
	0xC0, // ##    
	0xE0, // ###   
	0x78, //  #### 
	0x1C, //    ###
	0x0C, //     ##
	0xF8, // ##### 
	0x00, //       
	0x00, //       
	0x00, //       

	/* @1316 't' (5 pixels wide) */
	0x00, //      
	0x00, //      
	0x60, //  ##  
	0x60, //  ##  
	0xF8, // #####
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x60, //  ##  
	0x38, //   ###
	0x00, //      
	0x00, //      
	0x00, //      

	/* @1330 'u' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xCE, // ##  ###
	0x76, //  ### ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1344 'v' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x6C, //  ## ## 
	0x6C, //  ## ## 
	0x38, //   ###  
	0x38, //   ###  
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1358 'w' (10 pixels wide) */
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xD2, 0xC0, // ## #  # ##
	0x73, 0x80, //  ###  ### 
	0x61, 0x80, //  ##    ## 
	0x61, 0x80, //  ##    ## 
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           

	/* @1386 'x' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x6C, //  ## ## 
	0x38, //   ###  
	0x6C, //  ## ## 
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x00, //        
	0x00, //        
	0x00, //        

	/* @1400 'y' (7 pixels wide) */
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x6C, //  ## ## 
	0x6C, //  ## ## 
	0x38, //   ###  
	0x38, //   ###  
	0x18, //    ##  
	0x30, //   ##   
	0x30, //   ##   

	/* @1414 'z' (6 pixels wide) */
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0xFC, // ######
	0x0C, //     ##
	0x18, //    ## 
	0x30, //   ##  
	0x60, //  ##   
	0xC0, // ##    
	0xFC, // ######
	0x00, //       
	0x00, //       
	0x00, //       

	/* @1428 '{' (7 pixels wide) */
	0x00, //        
	0x0E, //     ###
	0x18, //    ##  
	0x18, //    ##  
	0x18, //    ##  
	0x30, //   ##   
	0xE0, // ###    
	0x30, //   ##   
	0x18, //    ##  
	0x18, //    ##  
	0x18, //    ##  
	0x18, //    ##  
	0x0E, //     ###
	0x00, //        

	/* @1442 '|' (2 pixels wide) */
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   

	/* @1456 '}' (7 pixels wide) */
	0x00, //        
	0xE0, // ###    
	0x30, //   ##   
	0x30, //   ##   
	0x30, //   ##   
	0x18, //    ##  
	0x0E, //     ###
	0x18, //    ##  
	0x30, //   ##   
	0x30, //   ##   
	0x30, //   ##   
	0x30, //   ##   
	0xE0, // ###    
	0x00, //        

	/* @1470 '~' (9 pixels wide) */
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x70, 0x80, //  ###    #
	0x88, 0x80, // #   #   #
	0x88, 0x80, // #   #   #
	0x87, 0x00, // #    ### 
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
	0x00, 0x00, //          
};


static fontInfo_t s_lib_font__standard__Descriptors[] =
{
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[0]}, 		/*   */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[14]}, 		/* ! */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[28]}, 		/* " */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[42]}, 		/* # */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[56]}, 		/* $ */
	{15, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[70]}, 		/* % */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[98]}, 		/* & */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[126]}, 		/* ' */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[140]}, 		/* ( */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[154]}, 		/* ) */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[168]}, 		/* * */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[182]}, 		/* + */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[196]}, 		/* , */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[210]}, 		/* - */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[224]}, 		/* . */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[238]}, 		/* / */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[252]}, 		/* 0 */
	{6,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[266]}, 		/* 1 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[280]}, 		/* 2 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[294]}, 		/* 3 */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[308]}, 		/* 4 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[322]}, 		/* 5 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[336]}, 		/* 6 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[350]}, 		/* 7 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[364]}, 		/* 8 */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[378]}, 		/* 9 */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[392]}, 		/* : */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[406]}, 		/* ; */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[420]}, 		/* < */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[434]}, 		/* = */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[448]}, 		/* > */
	{6,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[462]}, 		/* ? */
	{11, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[476]}, 		/* @ */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[504]}, 		/* A */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[518]}, 		/* B */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[532]}, 		/* C */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[546]}, 		/* D */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[560]}, 		/* E */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[574]}, 		/* F */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[588]}, 		/* G */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[602]}, 		/* H */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[630]}, 		/* I */
	{6,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[644]}, 		/* J */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[658]}, 		/* K */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[672]}, 		/* L */
	{10, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[686]}, 		/* M */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[714]}, 		/* N */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[728]}, 		/* O */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[756]}, 		/* P */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[770]}, 		/* Q */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[798]}, 		/* R */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[812]}, 		/* S */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[826]}, 		/* T */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[840]}, 		/* U */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[854]}, 		/* V */
	{12, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[868]}, 		/* W */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[896]}, 		/* X */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[910]}, 		/* Y */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[924]}, 		/* Z */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[938]}, 		/* [ */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[952]}, 		/* \ */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[966]}, 		/* ] */
	{8,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[980]}, 		/* ^ */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[994]}, 		/* _ */
	{3,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1022]}, 		/* ` */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1036]}, 		/* a */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1050]}, 		/* b */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1064]}, 		/* c */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1078]}, 		/* d */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1092]}, 		/* e */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1106]}, 		/* f */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1120]}, 		/* g */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1134]}, 		/* h */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1148]}, 		/* i */
	{4,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1162]}, 		/* j */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1176]}, 		/* k */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1190]}, 		/* l */
	{12, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1204]}, 		/* m */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1232]}, 		/* n */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1246]}, 		/* o */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1260]}, 		/* p */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1274]}, 		/* q */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1288]}, 		/* r */
	{6,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1302]}, 		/* s */
	{5,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1316]}, 		/* t */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1330]}, 		/* u */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1344]}, 		/* v */
	{10, LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1358]}, 		/* w */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1386]}, 		/* x */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1400]}, 		/* y */
	{6,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1414]}, 		/* z */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1428]}, 		/* { */
	{2,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1442]}, 		/* | */
	{7,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1456]}, 		/* } */
	{9,  LIB_FONT__STANDARD__FONT_HEIGHT, &s_lib_font__standard__Bitmaps[1470]}, 		/* ~ */
};

static uint8_t lib_font__isCharSupported(char c)
{
	/* all printable chars are supported ... */
	if(lib_font__standard__isCharPrintable(c))
		return 1;

	/* ... and the space char */
	if (c == ' ')
		return 1;

	return 0;
}

uint16_t lib_font__standard__getFontHeight(void)
{
	return LIB_FONT__STANDARD__FONT_HEIGHT;
}

uint8_t lib_font__standard__isCharPrintable(char c)
{
	if (c <= ' ' || c > '~')
		return 0;
	return 1;
}

fontInfo_t lib_font__standard__getCharInfo(char inChar)
{
	/* unsupported chars shall be treated as '?' */
	if (lib_font__isCharSupported(inChar) == 0)
		inChar = '?';
	
	return s_lib_font__standard__Descriptors[inChar - ' '];
}

