/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High-Performance Interior Point Method.                                                *
* Copyright (C) 2019 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* The 2-Clause BSD License                                                                        *
*                                                                                                 *
* Redistribution and use in source and binary forms, with or without                              *
* modification, are permitted provided that the following conditions are met:                     *
*                                                                                                 *
* 1. Redistributions of source code must retain the above copyright notice, this                  *
*    list of conditions and the following disclaimer.                                             *
* 2. Redistributions in binary form must reproduce the above copyright notice,                    *
*    this list of conditions and the following disclaimer in the documentation                    *
*    and/or other materials provided with the distribution.                                       *
*                                                                                                 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND                 *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED                   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                          *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR                 *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                    *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND                     *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT                      *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS                   *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                    *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



int DENSE_QP_DIM_MEMSIZE()
	{

	int size = 0;

	size = (size+8-1)/8*8;

	return size;

	}



void DENSE_QP_DIM_CREATE(struct DENSE_QP_DIM *size, void *memory)
	{

	size->memsize = DENSE_QP_DIM_MEMSIZE();

	return;

	}


void DENSE_QP_DIM_SET_ALL(int nv, int ne, int nb, int ng, int nsb, int nsg, struct DENSE_QP_DIM *size)
	{

	size->nv = nv;
	size->ne = ne;
	size->nb = nb;
	size->ng = ng;
	size->ns = nsb+nsg;
	size->nsb = nsb;
	size->nsg = nsg;

	return;

	}


void DENSE_QP_DIM_SET(char *field_name, int value, struct DENSE_QP_DIM *dim)
	{
	if(hpipm_strcmp(field_name, "nv"))
		{ 
		dim->nv = value;
		}
	else if(hpipm_strcmp(field_name, "ne"))
		{ 
		dim->ne = value;
		}
	else if(hpipm_strcmp(field_name, "nb"))
		{
		dim->nb = value;
		}
	else if(hpipm_strcmp(field_name, "ng"))
		{
		dim->ng = value;
		}
	else if(hpipm_strcmp(field_name, "nsb"))
		{
		dim->nsb = value;
		dim->ns = dim->nsb + dim->nsg;
		}
	else if(hpipm_strcmp(field_name, "nsg"))
		{
		dim->nsg = value;
		dim->ns = dim->nsb + dim->nsg;
		}
	else if(hpipm_strcmp(field_name, "ns"))
		{
		dim->ns = value;
		}
	else 
		{
		printf("error: SET_OCP_QP_DIM: wrong field %s\n", field_name);
		exit(1);
		}
	return;
	}




