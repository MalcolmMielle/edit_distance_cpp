#ifndef NORMALIZEDED_AASS
#define NORMALIZEDED_AASS

#include <iostream>
#include <stdio.h>
#include <fstream>

#include "Levenshtein.hpp"

namespace AASS{
	namespace editdistance{
		
		
		inline double GLS(const std::string& string_to_modify, const std::string& unchanged, std::string& out){
		
			double x_size = string_to_modify.size();
			double y_size = unchanged.size();
			double dist = levenshteinDistance(string_to_modify, unchanged, out);
			
			double up = ( 1 * ( x_size + y_size ) ) - dist;
			up = up/2;
			return up;
			
		}
		
		/**
		* @brief Normalized Levenshtein distance between two string
		* 
		* See :  Li Yujian and Liu Bo. “A Normalized Levenshtein Distance Metric” - 2007
		* 
		* @param[in] string_to_modify : input string
		* @param[in] unchanged : model string
		* @param[in] out : string describing the modification necesseary to go from input string to output string
		* 
		* @return normalized edit-distance
		*/
		inline double normalizedEditDistance(const std::string& string_to_modify, const std::string& unchanged, std::string& out){
			
			std::cout << "In for " << string_to_modify << " " << unchanged << std::endl;
			if(string_to_modify == unchanged){
// 				std::cout << "Strings are equal" << std::endl;
				return 0;
			}
			else{
				double dn_gld = 0;
				
				std::string out_xx;
				std::string out_yy;
				double GLS_XX = GLS(string_to_modify, string_to_modify, out_xx);
				std::cout << "GLS_xx : " << GLS_XX << std::endl;
				double GLS_YY =  GLS(unchanged, unchanged, out_yy);
				std::cout << "GLS_yy : " << GLS_YY << std::endl;
				double GLS_XY = GLS(string_to_modify, unchanged, out);
				std::cout << "GLS_xy : " << GLS_XY << std::endl;
				
				double dn_gld_up = GLS_XX + GLS_YY - (2 *  GLS_XY);
				double dn_gld_down = GLS_XX + GLS_YY - GLS_XY;
				
				if(dn_gld_down == 0){
					throw std::runtime_error("Dividing by zero");
				}
				
				dn_gld = dn_gld_up / dn_gld_down;
				return dn_gld;
			}
			
		}
		
	}
}
#endif