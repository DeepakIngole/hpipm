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



int DENSE_QP_IPM_ARG_MEMSIZE(struct DENSE_QP_DIM *dim)
	{

	return 0;

	}



void DENSE_QP_IPM_ARG_CREATE(struct DENSE_QP_DIM *dim, struct DENSE_QP_IPM_ARG *arg, void *mem)
	{

	arg->memsize = 0;

	return;

	}



void DENSE_QP_IPM_ARG_SET_DEFAULT(enum HPIPM_MODE mode, struct DENSE_QP_IPM_ARG *arg)
	{

	if(mode==SPEED_ABS)
		{
		arg->mu0 = 1e1;
		arg->alpha_min = 1e-12;
		arg->res_g_max = 1e0; // not used
		arg->res_b_max = 1e0; // not used
		arg->res_d_max = 1e0; // not used
		arg->res_m_max = 1e-8;
		arg->iter_max = 15;
		arg->stat_max = 15;
		arg->pred_corr = 1;
		arg->cond_pred_corr = 0; // not used
		arg->itref_pred_max = 0; // not used
		arg->itref_corr_max = 0; // not used
		arg->reg_prim = 1e-15;
		arg->reg_dual = 1e-15;
		arg->lq_fact = 0; // not used
		arg->scale = 0;
		arg->lam_min = 1e-30;
		arg->t_min = 1e-30;
		arg->warm_start = 0;
		arg->abs_form = 1;
		arg->comp_res_exit = 0;
		arg->comp_res_pred = 0;
		arg->mode = mode;
		}
	else if(mode==SPEED)
		{
		arg->mu0 = 1e1;
		arg->alpha_min = 1e-12;
		arg->res_g_max = 1e-6;
		arg->res_b_max = 1e-8;
		arg->res_d_max = 1e-8;
		arg->res_m_max = 1e-8;
		arg->iter_max = 15;
		arg->stat_max = 15;
		arg->pred_corr = 1;
		arg->cond_pred_corr = 1;
		arg->itref_pred_max = 0;
		arg->itref_corr_max = 0;
		arg->reg_prim = 1e-15;
		arg->reg_dual = 1e-15;
		arg->lq_fact = 0;
		arg->scale = 0;
		arg->lam_min = 1e-30;
		arg->t_min = 1e-30;
		arg->warm_start = 0;
		arg->abs_form = 0;
		arg->comp_res_exit = 1;
		arg->comp_res_pred = 0;
		arg->mode = mode;
		}
	else if(mode==BALANCE)
		{
		arg->mu0 = 1e1;
		arg->alpha_min = 1e-12;
		arg->res_g_max = 1e-6;
		arg->res_b_max = 1e-8;
		arg->res_d_max = 1e-8;
		arg->res_m_max = 1e-8;
		arg->iter_max = 30;
		arg->stat_max = 30;
		arg->pred_corr = 1;
		arg->cond_pred_corr = 1;
		arg->itref_pred_max = 0;
		arg->itref_corr_max = 2;
		arg->reg_prim = 1e-15;
		arg->reg_dual = 1e-15;
		arg->lq_fact = 1;
		arg->scale = 1;
		arg->lam_min = 1e-30;
		arg->t_min = 1e-30;
		arg->warm_start = 0;
		arg->abs_form = 0;
		arg->comp_res_exit = 1;
		arg->comp_res_pred = 0;
		arg->mode = mode;
		}
	else if(mode==ROBUST)
		{
		arg->mu0 = 1e2;
		arg->alpha_min = 1e-12;
		arg->res_g_max = 1e-6;
		arg->res_b_max = 1e-8;
		arg->res_d_max = 1e-8;
		arg->res_m_max = 1e-8;
		arg->iter_max = 100;
		arg->stat_max = 100;
		arg->pred_corr = 1;
		arg->cond_pred_corr = 1;
		arg->itref_pred_max = 0;
		arg->itref_corr_max = 4;
		arg->reg_prim = 1e-15;
		arg->reg_dual = 1e-15;
		arg->lq_fact = 2;
		arg->scale = 0;
		arg->lam_min = 1e-30;
		arg->t_min = 1e-30;
		arg->warm_start = 0;
		arg->abs_form = 0;
		arg->comp_res_exit = 1;
		arg->comp_res_pred = 0;
		arg->mode = mode;
		}
	else
		{
		printf("\nerror: DENSE_QP_IPM_ARG_SET_DEFAULT: wrong set default mode\n");
		exit(1);
		}

	return;

	}



void DENSE_QP_IPM_ARG_SET(char *field, void *value, struct DENSE_QP_IPM_ARG *arg)
	{
	if(hpipm_strcmp(field, "iter_max")) 
		{
		DENSE_QP_IPM_ARG_SET_ITER_MAX(value, arg);
		}
	else if(hpipm_strcmp(field, "alpha_min")) 
		{
		DENSE_QP_IPM_ARG_SET_ALPHA_MIN(value, arg);
		}
	else if(hpipm_strcmp(field, "mu0")) 
		{
		DENSE_QP_IPM_ARG_SET_MU0(value, arg);
		}
	else if(hpipm_strcmp(field, "tol_stat")) 
		{
		DENSE_QP_IPM_ARG_SET_TOL_STAT(value, arg);
		}
	else if(hpipm_strcmp(field, "tol_eq")) 
		{
		DENSE_QP_IPM_ARG_SET_TOL_EQ(value, arg);
		}
	else if(hpipm_strcmp(field, "tol_ineq")) 
		{
		DENSE_QP_IPM_ARG_SET_TOL_INEQ(value, arg);
		}
	else if(hpipm_strcmp(field, "tol_comp")) 
		{
		DENSE_QP_IPM_ARG_SET_TOL_COMP(value, arg);
		}
	else if(hpipm_strcmp(field, "reg_prim")) 
		{
		DENSE_QP_IPM_ARG_SET_REG_PRIM(value, arg);
		}
	else if(hpipm_strcmp(field, "reg_dual")) 
		{
		DENSE_QP_IPM_ARG_SET_REG_DUAL(value, arg);
		}
	else if(hpipm_strcmp(field, "warm_start")) 
		{
		DENSE_QP_IPM_ARG_SET_WARM_START(value, arg);
		}
	else if(hpipm_strcmp(field, "pred_corr")) 
		{
		DENSE_QP_IPM_ARG_SET_PRED_CORR(value, arg);
		}
	else if(hpipm_strcmp(field, "comp_res_pred")) 
		{
		DENSE_QP_IPM_ARG_SET_COMP_RES_PRED(value, arg);
		}
	else
		{
		printf("error: DENSE_QP_IPM_ARG_SET: wrong field %s\n", field);
		exit(1);	
		}
	return;
	}



void DENSE_QP_IPM_ARG_SET_ITER_MAX(int *iter_max, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->iter_max = *iter_max;
	return;
	}



void DENSE_QP_IPM_ARG_SET_ALPHA_MIN(REAL *alpha_min, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->alpha_min = *alpha_min;
	return;
	}



void DENSE_QP_IPM_ARG_SET_MU0(REAL *mu0, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->mu0 = *mu0;
	return;
	}



void DENSE_QP_IPM_ARG_SET_TOL_STAT(REAL *tol_stat, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->res_g_max = *tol_stat;
	return;
	}



void DENSE_QP_IPM_ARG_SET_TOL_EQ(REAL *tol_eq, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->res_b_max = *tol_eq;
	return;
	}



void DENSE_QP_IPM_ARG_SET_TOL_INEQ(REAL *tol_ineq, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->res_d_max = *tol_ineq;
	return;
	}



void DENSE_QP_IPM_ARG_SET_TOL_COMP(REAL *tol_comp, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->res_m_max = *tol_comp;
	return;
	}



void DENSE_QP_IPM_ARG_SET_REG_PRIM(REAL *reg, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->reg_prim = *reg;
	return;
	}



void DENSE_QP_IPM_ARG_SET_REG_DUAL(REAL *reg, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->reg_dual = *reg;
	return;
	}



void DENSE_QP_IPM_ARG_SET_WARM_START(int *warm_start, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->warm_start = *warm_start;
	return;
	}



void DENSE_QP_IPM_ARG_SET_PRED_CORR(int *pred_corr, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->pred_corr = *pred_corr;
	return;
	}



void DENSE_QP_IPM_ARG_SET_COMP_RES_PRED(int *comp_res_pred, struct DENSE_QP_IPM_ARG *arg)
	{
	arg->comp_res_pred = *comp_res_pred;
	return;
	}



int DENSE_QP_IPM_WS_MEMSIZE(struct DENSE_QP_DIM *dim, struct DENSE_QP_IPM_ARG *arg)
	{

	int nv = dim->nv;
	int ne = dim->ne;
	int nb = dim->nb;
	int ng = dim->ng;
	int ns = dim->ns;

	int size = 0;

	size += 1*sizeof(struct CORE_QP_IPM_WORKSPACE);
	size += 1*MEMSIZE_CORE_QP_IPM(nv+2*ns, ne, 2*nb+2*ng+2*ns);

	size += 1*sizeof(struct DENSE_QP_RES_WS); // res_workspace

	size += 2*sizeof(struct DENSE_QP); // qp_step qp_itref

	size += 2*sizeof(struct DENSE_QP_SOL); // sol_step sol_itref
	size += 1*DENSE_QP_SOL_MEMSIZE(dim); // sol_itref

	size += 2*sizeof(struct DENSE_QP_RES); // res res_itref
	size += 1*DENSE_QP_RES_MEMSIZE(dim); // res_itref

	size += 23*sizeof(struct STRVEC); // sol_step(v,pi,lam,t) res_g res_b res_d res_m lv (4+2)*tmp_nbg (1+1)*tmp_ns Gamma gamma Zs_inv sv se tmp_m
	size += 5*sizeof(struct STRMAT); // 2*Lv AL Le Ctx
	if(arg->lq_fact>0)
		size += 2*sizeof(struct STRMAT); // lq0 lq1

	size += 4*SIZE_STRVEC(nb+ng); // 4*tmp_nbg
	size += 1*SIZE_STRVEC(ns); // tmp_ns
	size += 2*SIZE_STRVEC(nv); // lv sv
	size += 1*SIZE_STRVEC(ne); // se
	size += 1*SIZE_STRVEC(2*ns); // Zs_inv
	size += 2*SIZE_STRMAT(nv+1, nv); // Lv
	size += 1*SIZE_STRMAT(ne, nv); // AL
	size += 1*SIZE_STRMAT(ne, ne); // Le
	size += 1*SIZE_STRMAT(nv+1, ng); // Ctx
	if(arg->lq_fact>0)
		{
		size += 1*SIZE_STRMAT(ne, ne+nv); // lq0
		size += 1*SIZE_STRMAT(nv, nv+nv+ng); // lq1
		}
	size += 1*SIZE_STRVEC(2*nb+2*ng+2*ns); // tmp_m

//	size += nv*sizeof(int); // ipiv_v // TODO remove !!!!!
//	size += ne*sizeof(int); // ipiv_e // TODO remove !!!!!

	if(arg->lq_fact>0)
		{
		size += 1*GELQF_WORKSIZE(ne, nv); // lq_work0
		size += 1*GELQF_WORKSIZE(nv, nv+nv+ng); // lq_work1
		}

	size += 9*(1+arg->stat_max)*sizeof(REAL); // stat

	size = (size+63)/64*64; // make multiple of typical cache line size
	size += 1*64; // align once to typical cache line size

	return size;

	}



void DENSE_QP_IPM_WS_CREATE(struct DENSE_QP_DIM *dim, struct DENSE_QP_IPM_ARG *arg, struct DENSE_QP_IPM_WS *workspace, void *mem)
	{

	int nv = dim->nv;
	int ne = dim->ne;
	int nb = dim->nb;
	int ng = dim->ng;
	int ns = dim->ns;


	// core struct
	struct CORE_QP_IPM_WORKSPACE *sr_ptr = mem;

	// core workspace
	workspace->core_workspace = sr_ptr;
	sr_ptr += 1;
	struct CORE_QP_IPM_WORKSPACE *cws = workspace->core_workspace;


	// res struct
	struct DENSE_QP_RES *res_ptr = (struct DENSE_QP_RES *) sr_ptr;

	workspace->res = res_ptr;
	res_ptr += 1;
	workspace->res_itref = res_ptr;
	res_ptr += 1;


	// res workspace struct
	struct DENSE_QP_RES_WS *res_ws_ptr = (struct DENSE_QP_RES_WS *) res_ptr;

	workspace->res_workspace = res_ws_ptr;
	res_ws_ptr += 1;


	// qp sol struct
	struct DENSE_QP_SOL *qp_sol_ptr = (struct DENSE_QP_SOL *) res_ws_ptr;

	workspace->sol_step = qp_sol_ptr;
	qp_sol_ptr += 1;
	workspace->sol_itref = qp_sol_ptr;
	qp_sol_ptr += 1;


	// qp struct
	struct DENSE_QP *qp_ptr = (struct DENSE_QP *) qp_sol_ptr;

	workspace->qp_step = qp_ptr;
	qp_ptr += 1;
	workspace->qp_itref = qp_ptr;
	qp_ptr += 1;


	// matrix struct
	struct STRMAT *sm_ptr = (struct STRMAT *) qp_ptr;

	workspace->Lv = sm_ptr;
	sm_ptr += 2;
	workspace->AL = sm_ptr;
	sm_ptr += 1;
	workspace->Le = sm_ptr;
	sm_ptr += 1;
	workspace->Ctx = sm_ptr;
	sm_ptr += 1;
	if(arg->lq_fact>0)
		{
		workspace->lq0 = sm_ptr;
		sm_ptr += 1;
		workspace->lq1 = sm_ptr;
		sm_ptr += 1;
		}


	// vector struct
	struct STRVEC *sv_ptr = (struct STRVEC *) sm_ptr;

	workspace->sol_step->v = sv_ptr;
	sv_ptr += 1;
	workspace->sol_step->pi = sv_ptr;
	sv_ptr += 1;
	workspace->sol_step->lam = sv_ptr;
	sv_ptr += 1;
	workspace->sol_step->t = sv_ptr;
	sv_ptr += 1;
	workspace->res->res_g = sv_ptr;
	sv_ptr += 1;
	workspace->res->res_b = sv_ptr;
	sv_ptr += 1;
	workspace->res->res_d = sv_ptr;
	sv_ptr += 1;
	workspace->res->res_m = sv_ptr;
	sv_ptr += 1;
	workspace->Gamma = sv_ptr;
	sv_ptr += 1;
	workspace->gamma = sv_ptr;
	sv_ptr += 1;
	workspace->Zs_inv = sv_ptr;
	sv_ptr += 1;
	workspace->lv = sv_ptr;
	sv_ptr += 1;
	workspace->sv = sv_ptr;
	sv_ptr += 1;
	workspace->se = sv_ptr;
	sv_ptr += 1;
	workspace->tmp_nbg = sv_ptr;
	sv_ptr += 4;
	workspace->res_workspace->tmp_nbg = sv_ptr;
	sv_ptr += 2;
	workspace->tmp_ns = sv_ptr;
	sv_ptr += 1;
	workspace->res_workspace->tmp_ns = sv_ptr;
	sv_ptr += 1;
	workspace->tmp_m = sv_ptr;
	sv_ptr += 1;


	// double/float stuff
	REAL *d_ptr = (REAL *) sv_ptr;
	
	workspace->stat = d_ptr;
	d_ptr += 9*(1+arg->stat_max);


	// int suff
	int *i_ptr = (int *) d_ptr;

//	workspace->ipiv_v = i_ptr;
//	i_ptr += nv;

//	workspace->ipiv_e = i_ptr;
//	i_ptr += ne;


	// align to typicl cache line size
	size_t s_ptr = (size_t) i_ptr;
	s_ptr = (s_ptr+63)/64*64;


	// void stuf
	char *c_ptr = (char *) s_ptr;

	DENSE_QP_SOL_CREATE(dim, workspace->sol_itref, c_ptr);
	c_ptr += workspace->sol_itref->memsize;

	DENSE_QP_RES_CREATE(dim, workspace->res_itref, c_ptr);
	c_ptr += workspace->res_itref->memsize;

	CREATE_STRMAT(nv+1, nv, workspace->Lv, c_ptr);
	c_ptr += workspace->Lv->memsize;

	CREATE_STRMAT(nv+1, nv, workspace->Lv+1, c_ptr);
	c_ptr += workspace->Lv[1].memsize;

	CREATE_STRMAT(ne, nv, workspace->AL, c_ptr);
	c_ptr += workspace->AL->memsize;

	CREATE_STRMAT(ne, ne, workspace->Le, c_ptr);
	c_ptr += workspace->Le->memsize;

	CREATE_STRMAT(nv+1, ng, workspace->Ctx, c_ptr);
	c_ptr += workspace->Ctx->memsize;

	if(arg->lq_fact>0)
		{
		CREATE_STRMAT(ne, ne+nv, workspace->lq0, c_ptr);
		c_ptr += workspace->lq0->memsize;

		CREATE_STRMAT(nv, nv+nv+ng, workspace->lq1, c_ptr);
		c_ptr += workspace->lq1->memsize;
		}

	CREATE_STRVEC(nv, workspace->lv, c_ptr);
	c_ptr += workspace->lv->memsize;

	CREATE_STRVEC(nv, workspace->sv, c_ptr);
	c_ptr += workspace->sv->memsize;

	CREATE_STRVEC(ne, workspace->se, c_ptr);
	c_ptr += workspace->se->memsize;

	CREATE_STRVEC(2*ns, workspace->Zs_inv, c_ptr);
	c_ptr += workspace->Zs_inv->memsize;

	CREATE_STRVEC(nb+ng, workspace->tmp_nbg+0, c_ptr);
	CREATE_STRVEC(nb+ng, workspace->res_workspace->tmp_nbg+0, c_ptr);
	c_ptr += (workspace->tmp_nbg+0)->memsize;

	CREATE_STRVEC(nb+ng, workspace->tmp_nbg+1, c_ptr);
	CREATE_STRVEC(nb+ng, workspace->res_workspace->tmp_nbg+1, c_ptr);
	c_ptr += (workspace->tmp_nbg+1)->memsize;

	CREATE_STRVEC(nb+ng, workspace->tmp_nbg+2, c_ptr);
	c_ptr += (workspace->tmp_nbg+2)->memsize;

	CREATE_STRVEC(nb+ng, workspace->tmp_nbg+3, c_ptr);
	c_ptr += (workspace->tmp_nbg+3)->memsize;

	CREATE_STRVEC(ns, workspace->tmp_ns+0, c_ptr);
	CREATE_STRVEC(ns, workspace->res_workspace->tmp_ns+0, c_ptr);
	c_ptr += (workspace->tmp_ns+0)->memsize;

	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->tmp_m, c_ptr);
	c_ptr += (workspace->tmp_m)->memsize;

	CREATE_CORE_QP_IPM(nv+2*ns, ne, 2*nb+2*ng+2*ns, cws, c_ptr);
	c_ptr += workspace->core_workspace->memsize;

	if(arg->lq_fact>0)
		{
		workspace->lq_work0 = c_ptr;
		c_ptr += GELQF_WORKSIZE(ne, nv);

		workspace->lq_work1 = c_ptr;
		c_ptr += GELQF_WORKSIZE(nv, nv+nv+ng);
		}


	// alias members of workspace and core_workspace
	//
	CREATE_STRVEC(nv+2*ns, workspace->sol_step->v, cws->dv);
	//
	CREATE_STRVEC(ne, workspace->sol_step->pi, cws->dpi);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->sol_step->lam, cws->dlam);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->sol_step->t, cws->dt);
	//
	CREATE_STRVEC(nv+2*ns, workspace->res->res_g, cws->res_g);
	//
	CREATE_STRVEC(ne, workspace->res->res_b, cws->res_b);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->res->res_d, cws->res_d);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->res->res_m, cws->res_m);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->Gamma, cws->Gamma);
	//
	CREATE_STRVEC(2*nb+2*ng+2*ns, workspace->gamma, cws->gamma);

	//
	workspace->sol_step->dim = dim;

	workspace->stat_max = arg->stat_max;

	workspace->stat_m = 9;

	//
	workspace->use_hess_fact = 0;

	//
	workspace->memsize = DENSE_QP_IPM_WS_MEMSIZE(dim, arg);


#if defined(RUNTIME_CHECKS)
	if(c_ptr > ((char *) mem) + workspace->memsize)
		{
		printf("\nCreate_dense_qp_ipm: outside memory bounds!\n\n");
		exit(1);
		}
#endif


	return;

	}



void DENSE_QP_IPM_GET(char *field, struct DENSE_QP_IPM_WS *ws, void *value)
	{
	if(hpipm_strcmp(field, "status"))
		{ 
		DENSE_QP_IPM_GET_STATUS(ws, value);
		}
	else if(hpipm_strcmp(field, "iter"))
		{ 
		DENSE_QP_IPM_GET_ITER(ws, value);
		}
	else if(hpipm_strcmp(field, "max_res_stat"))
		{ 
		DENSE_QP_IPM_GET_MAX_RES_STAT(ws, value);
		}
	else if(hpipm_strcmp(field, "max_res_eq"))
		{ 
		DENSE_QP_IPM_GET_MAX_RES_EQ(ws, value);
		}
	else if(hpipm_strcmp(field, "max_res_ineq"))
		{ 
		DENSE_QP_IPM_GET_MAX_RES_INEQ(ws, value);
		}
	else if(hpipm_strcmp(field, "max_res_comp"))
		{ 
		DENSE_QP_IPM_GET_MAX_RES_COMP(ws, value);
		}
	else if(hpipm_strcmp(field, "stat"))
		{ 
		DENSE_QP_IPM_GET_STAT(ws, value);
		}
	else if(hpipm_strcmp(field, "stat_m"))
		{ 
		DENSE_QP_IPM_GET_STAT_M(ws, value);
		}
	else 
		{
		printf("error: DENSE_QP_IPM_GET: wrong field %s\n", field);
		exit(1);
		}
	return;
	}



void DENSE_QP_IPM_GET_STATUS(struct DENSE_QP_IPM_WS *ws, int *status)
	{
	*status = ws->status;
	return;
	}



void DENSE_QP_IPM_GET_ITER(struct DENSE_QP_IPM_WS *ws, int *iter)
	{
	*iter = ws->iter;
	return;
	}



void DENSE_QP_IPM_GET_MAX_RES_STAT(struct DENSE_QP_IPM_WS *ws, REAL *res_stat)
	{
	*res_stat = ws->qp_res[0];
	return;
	}



void DENSE_QP_IPM_GET_MAX_RES_EQ(struct DENSE_QP_IPM_WS *ws, REAL *res_eq)
	{
	*res_eq = ws->qp_res[1];
	return;
	}



void DENSE_QP_IPM_GET_MAX_RES_INEQ(struct DENSE_QP_IPM_WS *ws, REAL *res_ineq)
	{
	*res_ineq = ws->qp_res[2];
	return;
	}



void DENSE_QP_IPM_GET_MAX_RES_COMP(struct DENSE_QP_IPM_WS *ws, REAL *res_comp)
	{
	*res_comp = ws->qp_res[3];
	return;
	}



void DENSE_QP_IPM_GET_STAT(struct DENSE_QP_IPM_WS *ws, REAL **stat)
	{
	*stat = ws->stat;
	}



void DENSE_QP_IPM_GET_STAT_M(struct DENSE_QP_IPM_WS *ws, int *stat_m)
	{
	*stat_m = ws->stat_m;
	}



void DENSE_QP_IPM_SOLVE(struct DENSE_QP *qp, struct DENSE_QP_SOL *qp_sol, struct DENSE_QP_IPM_ARG *arg, struct DENSE_QP_IPM_WS *ws)
	{

	struct CORE_QP_IPM_WORKSPACE *cws = ws->core_workspace;

	// arg to core workspace
	cws->lam_min = arg->lam_min;
	cws->t_min = arg->t_min;

	// alias qp vectors into qp_sol
	cws->v = qp_sol->v->pa;
	cws->pi = qp_sol->pi->pa;
	cws->lam = qp_sol->lam->pa;
	cws->t = qp_sol->t->pa;

	// alias members of qp_step
	ws->qp_step->dim = qp->dim;
	ws->qp_step->Hv = qp->Hv;
	ws->qp_step->A = qp->A;
	ws->qp_step->Ct = qp->Ct;
	ws->qp_step->Z = qp->Z;
	ws->qp_step->idxb = qp->idxb;
	ws->qp_step->idxs = qp->idxs;
	ws->qp_step->gz = ws->res->res_g;
	ws->qp_step->b = ws->res->res_b;
	ws->qp_step->d = ws->res->res_d;
	ws->qp_step->m = ws->res->res_m;

	// alias members of qp_itref
	ws->qp_itref->dim = qp->dim;
	ws->qp_itref->Hv = qp->Hv;
	ws->qp_itref->A = qp->A;
	ws->qp_itref->Ct = qp->Ct;
	ws->qp_itref->Z = qp->Z;
	ws->qp_itref->idxb = qp->idxb;
	ws->qp_itref->idxs = qp->idxs;
	ws->qp_itref->gz = ws->res_itref->res_g;
	ws->qp_itref->b = ws->res_itref->res_b;
	ws->qp_itref->d = ws->res_itref->res_d;
	ws->qp_itref->m = ws->res_itref->res_m;

	// blasfeo alias for residuals
	struct STRVEC str_res_g;
	struct STRVEC str_res_b;
	struct STRVEC str_res_d;
	struct STRVEC str_res_m;
	str_res_g.m = cws->nv;
	str_res_b.m = cws->ne;
	str_res_d.m = cws->nc;
	str_res_m.m = cws->nc;
	str_res_g.pa = cws->res_g;
	str_res_b.pa = cws->res_b;
	str_res_d.pa = cws->res_d;
	str_res_m.pa = cws->res_m;

	REAL *qp_res = ws->qp_res;
	qp_res[0] = 0;
	qp_res[1] = 0;
	qp_res[2] = 0;
	qp_res[3] = 0;

	// no constraints
	if(cws->nc==0)
		{
		FACT_SOLVE_KKT_UNCONSTR_DENSE_QP(qp, qp_sol, arg, ws);
		DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);
		// compute infinity norm of residuals
		VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
		VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
		VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
		VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);
		if(0<ws->stat_max)
			{
			ws->stat[5] = qp_res[0];
			ws->stat[6] = qp_res[1];
			ws->stat[7] = qp_res[2];
			ws->stat[8] = qp_res[3];
			}
		cws->mu = ws->res->res_mu;
		ws->iter = 0;
		ws->status = 0;
		return;
		}
	
	// dims
	int nv = qp->dim->nv;
	int ne = qp->dim->ne;
	int nb = qp->dim->nb;
	int ng = qp->dim->ng;
	int ns = qp->dim->ns;

	int kk, ii, itref0=0, itref1=0;
	REAL tmp;
	REAL mu_aff0, mu;
	int iter_ref_step;

	// init solver
	INIT_VAR_DENSE_QP(qp, qp_sol, arg, ws);

	cws->alpha = 1.0;



	// absolute IPM formulation

	if(arg->abs_form)
		{

		// alias members of qp_step
		ws->qp_step->dim = qp->dim;
		ws->qp_step->Hv = qp->Hv;
		ws->qp_step->A = qp->A;
		ws->qp_step->Ct = qp->Ct;
		ws->qp_step->Z = qp->Z;
		ws->qp_step->idxb = qp->idxb;
		ws->qp_step->idxs = qp->idxs;
		ws->qp_step->gz = qp->gz;
		ws->qp_step->b = qp->b;
		ws->qp_step->d = qp->d;
		ws->qp_step->m = ws->tmp_m;

		// alias core workspace
		cws->res_m = ws->qp_step->m->pa;
		cws->res_m_bkp = ws->qp_step->m->pa;

		mu = VECMULDOT(cws->nc, qp_sol->lam, 0, qp_sol->t, 0, ws->tmp_m, 0);
		mu /= cws->nc;
		cws->mu = mu;

		// IPM loop (absolute formulation)
		for(kk=0; \
				kk<arg->iter_max & \
				cws->alpha>arg->alpha_min & \
				mu>arg->res_m_max; kk++)
			{

			VECSC(cws->nc, -1.0, ws->tmp_m, 0);

			// fact solve
			FACT_SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

			// compute step
			AXPY(cws->nv, -1.0, qp_sol->v, 0, ws->sol_step->v, 0, ws->sol_step->v, 0);
			AXPY(cws->ne, -1.0, qp_sol->pi, 0, ws->sol_step->pi, 0, ws->sol_step->pi, 0);
			AXPY(cws->nc, -1.0, qp_sol->lam, 0, ws->sol_step->lam, 0, ws->sol_step->lam, 0);
			AXPY(cws->nc, -1.0, qp_sol->t, 0, ws->sol_step->t, 0, ws->sol_step->t, 0);

			// alpha
			COMPUTE_ALPHA_QP(cws);
			if(kk+1<ws->stat_max)
				ws->stat[ws->stat_m*(kk+1)+0] = cws->alpha;

			// Mehrotra's predictor-corrector
			if(arg->pred_corr==1)
				{
				// mu_aff
				COMPUTE_MU_AFF_QP(cws);
				if(kk+1<ws->stat_max)
					ws->stat[ws->stat_m*(kk+1)+1] = cws->mu_aff;

				tmp = cws->mu_aff/cws->mu;
				cws->sigma = tmp*tmp*tmp;
				if(kk+1<ws->stat_max)
					ws->stat[ws->stat_m*(kk+1)+2] = cws->sigma;

				COMPUTE_CENTERING_CORRECTION_QP(cws);

				// fact and solve kkt
				SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

				// compute step
				AXPY(cws->nv, -1.0, qp_sol->v, 0, ws->sol_step->v, 0, ws->sol_step->v, 0);
				AXPY(cws->ne, -1.0, qp_sol->pi, 0, ws->sol_step->pi, 0, ws->sol_step->pi, 0);
				AXPY(cws->nc, -1.0, qp_sol->lam, 0, ws->sol_step->lam, 0, ws->sol_step->lam, 0);
				AXPY(cws->nc, -1.0, qp_sol->t, 0, ws->sol_step->t, 0, ws->sol_step->t, 0);

				// alpha
				COMPUTE_ALPHA_QP(cws);
				if(kk+1<ws->stat_max)
					ws->stat[ws->stat_m*(kk+1)+3] = cws->alpha;

				}

			//
			UPDATE_VAR_QP(cws);

			// compute mu
			mu = VECMULDOT(cws->nc, qp_sol->lam, 0, qp_sol->t, 0, ws->tmp_m, 0);
			mu /= cws->nc;
			cws->mu = mu;
			if(kk+1<ws->stat_max)
				ws->stat[ws->stat_m*(kk+1)+4] = mu;

	//		exit(1);

			}

		if(arg->comp_res_exit)
			{
			// compute residuals
			DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);

			// compute infinity norm of residuals
			VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
			VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
			VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
			VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);
			}

		ws->iter = kk;

		if(kk == arg->iter_max)
			{
			// max iteration number reached
			ws->status = 1;
			}
		else if(cws->alpha <= arg->alpha_min)
			{
			// min step lenght
			ws->status = 2;
			}
#ifdef USE_C99_MATH
		else if(isnan(cws->mu))
			{
			// NaN in the solution
			ws->status = 3;
			}
#else
		else if(cws->mu != cws->mu)
			{
			// NaN in the solution
			ws->status = 3;
			}
#endif
		else
			{
			// normal return
			ws->status = 0;
			}

		return;

		}



	// compute residuals
	DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);
	BACKUP_RES_M(cws);
	cws->mu = ws->res->res_mu;

	// compute infinity norm of residuals
	VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
	VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
	VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
	VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);

	if(0<ws->stat_max)
		{
		ws->stat[ws->stat_m*(0)+5] = qp_res[0];
		ws->stat[ws->stat_m*(0)+6] = qp_res[1];
		ws->stat[ws->stat_m*(0)+7] = qp_res[2];
		ws->stat[ws->stat_m*(0)+8] = qp_res[3];
		}

	REAL itref_qp_norm[4] = {0,0,0,0};
	REAL itref_qp_norm0[4] = {0,0,0,0};
	int ndp0, ndp1;

	int force_lq = 0;



	// relative IPM formulation

	// IPM loop
	for(kk=0; \
			kk<arg->iter_max & \
			cws->alpha>arg->alpha_min & \
			(qp_res[0]>arg->res_g_max | \
			qp_res[1]>arg->res_b_max | \
			qp_res[2]>arg->res_d_max | \
			qp_res[3]>arg->res_m_max); kk++)
		{

		ws->scale = arg->scale;

		// fact and solve kkt
		if(arg->lq_fact==0)
			{

			// syrk+cholesky
			FACT_SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

			}
		else if(arg->lq_fact==1 & force_lq==0)
			{

			// syrk+chol, switch to lq when needed
			FACT_SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

			// compute res of linear system
			DENSE_QP_RES_COMPUTE_LIN(ws->qp_step, qp_sol, ws->sol_step, ws->res_itref, ws->res_workspace);
			VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm[0]);
			VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm[1]);
			VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm[2]);
			VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm[3]);

//printf("\n%e\t%e\t%e\t%e\n", itref_qp_norm[0], itref_qp_norm[1], itref_qp_norm[2], itref_qp_norm[3]);

			// inaccurate factorization: switch to lq
			if(
#ifdef USE_C99_MATH
				( itref_qp_norm[0]==0.0 & isnan(BLASFEO_DVECEL(ws->res_itref->res_g, 0)) ) |
#else
				( itref_qp_norm[0]==0.0 & BLASFEO_DVECEL(ws->res_itref->res_g, 0)!=BLASFEO_DVECEL(ws->res_itref->res_g, 0) ) |
#endif
				itref_qp_norm[0]>1e-5 |
				itref_qp_norm[1]>1e-5 |
				itref_qp_norm[2]>1e-5 |
				itref_qp_norm[3]>1e-5 )
				{

#if 0
blasfeo_print_tran_dvec(cws->nv, ws->sol_step->v, 0);
blasfeo_print_tran_dvec(cws->ne, ws->sol_step->pi, 0);
blasfeo_print_tran_dvec(cws->nc, ws->sol_step->lam, 0);
blasfeo_print_tran_dvec(cws->nc, ws->sol_step->t, 0);
#endif

				// refactorize using lq
				FACT_LQ_SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

				// switch to lq
				force_lq = 1;

#if 0
blasfeo_print_tran_dvec(cws->nv, ws->sol_step->v, 0);
blasfeo_print_tran_dvec(cws->ne, ws->sol_step->pi, 0);
blasfeo_print_tran_dvec(cws->nc, ws->sol_step->lam, 0);
blasfeo_print_tran_dvec(cws->nc, ws->sol_step->t, 0);
#endif

				}

			}
		else // arg->lq_fact==2
			{

			// lq
			FACT_LQ_SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

			}



#if 0
		DENSE_QP_RES_COMPUTE_LIN(ws->qp_step, qp_sol, ws->sol_step, ws->res_itref, ws->res_workspace);
		VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm[0]);
		VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm[1]);
		VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm[2]);
		VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm[3]);
//		printf("%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3], itref_qp_norm[0], itref_qp_norm[1], itref_qp_norm[2], itref_qp_norm[3]);
		if(itref_qp_norm[0]==0.0 & BLASFEO_DVECEL(ws->res_itref->res_g, 0)!=BLASFEO_DVECEL(ws->res_itref->res_g, 0))
			printf("NaN!!!\n");
#endif

		// iterative refinement on prediction step
		for(itref0=0; itref0<arg->itref_pred_max; itref0++)
			{

			DENSE_QP_RES_COMPUTE_LIN(ws->qp_step, qp_sol, ws->sol_step, ws->res_itref, ws->res_workspace);

			VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm[0]);
			VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm[1]);
			VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm[2]);
			VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm[3]);

			if(itref0==0)
				{
				itref_qp_norm0[0] = itref_qp_norm[0];
				itref_qp_norm0[1] = itref_qp_norm[1];
				itref_qp_norm0[2] = itref_qp_norm[2];
				itref_qp_norm0[3] = itref_qp_norm[3];
				}

			if( \
					(itref_qp_norm[0]<1e0*arg->res_g_max | itref_qp_norm[0]<1e-3*qp_res[0]) & \
					(itref_qp_norm[1]<1e0*arg->res_b_max | itref_qp_norm[1]<1e-3*qp_res[1]) & \
					(itref_qp_norm[2]<1e0*arg->res_d_max | itref_qp_norm[2]<1e-3*qp_res[2]) & \
					(itref_qp_norm[3]<1e0*arg->res_m_max | itref_qp_norm[3]<1e-3*qp_res[3]) )
//					(itref_qp_norm[0]<=arg->res_g_max) & \
					(itref_qp_norm[1]<=arg->res_b_max) & \
					(itref_qp_norm[2]<=arg->res_d_max) & \
					(itref_qp_norm[3]<=arg->res_m_max) )
				{
				break;
				}

			SOLVE_KKT_STEP_DENSE_QP(ws->qp_itref, ws->sol_itref, arg, ws);

			AXPY(nv+2*ns, 1.0, ws->sol_itref->v, 0, ws->sol_step->v, 0, ws->sol_step->v, 0);
			AXPY(ne, 1.0, ws->sol_itref->pi, 0, ws->sol_step->pi, 0, ws->sol_step->pi, 0);
			AXPY(2*nb+2*ng+2*ns, 1.0, ws->sol_itref->lam, 0, ws->sol_step->lam, 0, ws->sol_step->lam, 0);
			AXPY(2*nb+2*ng+2*ns, 1.0, ws->sol_itref->t, 0, ws->sol_step->t, 0, ws->sol_step->t, 0);

			}

#if 0
		DENSE_QP_RES_COMPUTE_LIN(ws->qp_step, qp_sol, ws->sol_step, ws->res_itref, ws->res_workspace);
		VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm0[0]);
		VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm0[1]);
		VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm0[2]);
		VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm0[3]);
//		printf("\nkk = %d\n", kk);
//		blasfeo_print_exp_tran_dvec(qp->dim->nv, ws->res_itref->res_g, 0);
//		blasfeo_print_exp_tran_dvec(qp->dim->ne, ws->res_itref->res_b, 0);
//		blasfeo_print_exp_tran_dvec(2*qp->dim->nb+2*qp->dim->ng, ws->res_itref->res_d, 0);
#endif

#if 0
		DENSE_QP_RES_COMPUTE(ws->qp_step, ws->sol_step, ws->res_itref, ws->res_workspace);
		VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm0[0]);
		VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm0[1]);
		VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm0[2]);
		VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm0[3]);
//		printf("\nkk = %d\n", kk);
//		blasfeo_print_exp_tran_dvec(qp->dim->nv, ws->res_itref->res_g, 0);
//		blasfeo_print_exp_tran_dvec(qp->dim->ne, ws->res_itref->res_b, 0);
//		blasfeo_print_exp_tran_dvec(2*qp->dim->nb+2*qp->dim->ng, ws->res_itref->res_d, 0);
#endif

#if 0
		ndp0 = 0;
		for(ii=0; ii<qp->dim->nv; ii++)
			{
			if(ws->Lv->dA[ii]<=0)
				{
				ndp0 = ii;
				break;
				}
			}
		ndp1 = 0;
		for(ii=0; ii<qp->dim->ne; ii++)
			{
			if(ws->Le->dA[ii]<=0)
				{
				ndp1 = ii;
				break;
				}
			}
#endif

		// alpha
		COMPUTE_ALPHA_QP(cws);
		if(kk+1<ws->stat_max)
			ws->stat[ws->stat_m*(kk+1)+0] = cws->alpha;

		// Mehrotra's predictor-corrector
		if(arg->pred_corr==1)
			{
			// mu_aff
			COMPUTE_MU_AFF_QP(cws);
			if(kk+1<ws->stat_max)
				ws->stat[ws->stat_m*(kk+1)+1] = cws->mu_aff;

			// compute centering parameter
			tmp = cws->mu_aff/cws->mu;
			cws->sigma = tmp*tmp*tmp;
//			cws->sigma = sigma_min>cws->sigma ? sigma_min : cws->sigma;
			if(kk+1<ws->stat_max)
				ws->stat[ws->stat_m*(kk+1)+2] = cws->sigma;

			COMPUTE_CENTERING_CORRECTION_QP(cws);

			// solve kkt
			SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

			// alpha
			COMPUTE_ALPHA_QP(cws);
			if(kk+1<ws->stat_max)
				ws->stat[ws->stat_m*(kk+1)+3] = cws->alpha;

			// conditional Mehrotra's predictor-corrector
			if(arg->cond_pred_corr==1)
				{

				// save mu_aff (from prediction sol_step)
				mu_aff0 = cws->mu_aff;

				// compute mu for predictor-corrector-centering
				COMPUTE_MU_AFF_QP(cws);

//				if(cws->mu_aff > 2.0*cws->mu)
				if(cws->mu_aff > 2.0*mu_aff0)
					{

					// centering direction
					COMPUTE_CENTERING_QP(cws);

					// solve kkt
					SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

					// alpha
					COMPUTE_ALPHA_QP(cws);
					if(kk+1<ws->stat_max)
						ws->stat[ws->stat_m*(kk+1)+3] = cws->alpha;

					}

				}

			iter_ref_step = 0;
			for(itref1=0; itref1<arg->itref_corr_max; itref1++)
				{

				DENSE_QP_RES_COMPUTE_LIN(ws->qp_step, qp_sol, ws->sol_step, ws->res_itref, ws->res_workspace);

				VECNRM_INF(cws->nv, ws->res_itref->res_g, 0, &itref_qp_norm[0]);
				VECNRM_INF(cws->ne, ws->res_itref->res_b, 0, &itref_qp_norm[1]);
				VECNRM_INF(cws->nc, ws->res_itref->res_d, 0, &itref_qp_norm[2]);
				VECNRM_INF(cws->nc, ws->res_itref->res_m, 0, &itref_qp_norm[3]);

				if(itref1==0)
					{
					itref_qp_norm0[0] = itref_qp_norm[0];
					itref_qp_norm0[1] = itref_qp_norm[1];
					itref_qp_norm0[2] = itref_qp_norm[2];
					itref_qp_norm0[3] = itref_qp_norm[3];
					}

				if( \
						(itref_qp_norm[0]<1e0*arg->res_g_max | itref_qp_norm[0]<1e-3*qp_res[0]) & \
						(itref_qp_norm[1]<1e0*arg->res_b_max | itref_qp_norm[1]<1e-3*qp_res[1]) & \
						(itref_qp_norm[2]<1e0*arg->res_d_max | itref_qp_norm[2]<1e-3*qp_res[2]) & \
						(itref_qp_norm[3]<1e0*arg->res_m_max | itref_qp_norm[3]<1e-3*qp_res[3]) )
//						(itref_qp_norm[0]<=arg->res_g_max) & \
						(itref_qp_norm[1]<=arg->res_b_max) & \
						(itref_qp_norm[2]<=arg->res_d_max) & \
						(itref_qp_norm[3]<=arg->res_m_max) )
					{
					break;
					}

				SOLVE_KKT_STEP_DENSE_QP(ws->qp_itref, ws->sol_itref, arg, ws);
				iter_ref_step = 1;

				AXPY(nv+2*ns, 1.0, ws->sol_itref->v, 0, ws->sol_step->v, 0, ws->sol_step->v, 0);
				AXPY(ne, 1.0, ws->sol_itref->pi, 0, ws->sol_step->pi, 0, ws->sol_step->pi, 0);
				AXPY(2*nb+2*ng+2*ns, 1.0, ws->sol_itref->lam, 0, ws->sol_step->lam, 0, ws->sol_step->lam, 0);
				AXPY(2*nb+2*ng+2*ns, 1.0, ws->sol_itref->t, 0, ws->sol_step->t, 0, ws->sol_step->t, 0);

				}

			if(iter_ref_step)
				{
				// alpha
				COMPUTE_ALPHA_QP(cws);
				if(kk+1<ws->stat_max)
					ws->stat[ws->stat_m*(kk+1)+3] = cws->alpha;
				}

			}

		//
		UPDATE_VAR_QP(cws);

		// compute residuals
		DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);
		BACKUP_RES_M(cws);
		cws->mu = ws->res->res_mu;
		if(kk+1<ws->stat_max)
			ws->stat[ws->stat_m*(kk+1)+4] = ws->res->res_mu;

		// compute infinity norm of residuals
		VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
		VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
		VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
		VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);

		if(kk+1<ws->stat_max)
			{
			ws->stat[ws->stat_m*(kk+1)+5] = qp_res[0];
			ws->stat[ws->stat_m*(kk+1)+6] = qp_res[1];
			ws->stat[ws->stat_m*(kk+1)+7] = qp_res[2];
			ws->stat[ws->stat_m*(kk+1)+8] = qp_res[3];
			}

#if 0
printf("%e %e %e\n", cws->alpha, cws->alpha_prim, cws->alpha_dual);
#endif

#if 0
printf("%e %e %e %e %e\n", ws->stat[5*kk+0], ws->stat[5*kk+1], ws->stat[5*kk+2], ws->stat[5*kk+3], ws->stat[5*kk+4]);
#endif

#if 0
printf("%e %e %e %e\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3]);
#endif

#if 0
printf("iter %3d   alpha %1.3e %1.3e   sigma %1.3e   ndp %3d %3d   itref %d %d   res_kkt %1.3e %1.3e %1.3e %1.3e   res_kkt %1.3e %1.3e %1.3e %1.3e   res_qp %1.3e %1.3e %1.3e %1.3e\n", kk, cws->alpha_prim, cws->alpha_dual, cws->sigma, ndp0, ndp1, itref0, itref1, itref_qp_norm0[0], itref_qp_norm0[1], itref_qp_norm0[2], itref_qp_norm0[3], itref_qp_norm[0], itref_qp_norm[1], itref_qp_norm[2], itref_qp_norm[3], qp_res[0], qp_res[1], qp_res[2], qp_res[3]);
#endif

		}

	ws->iter = kk;

	if(kk == arg->iter_max)
		{
		// max iteration number reached
		ws->status = 1;
		}
	else if(cws->alpha <= arg->alpha_min)
		{
		// min step lenght
		ws->status = 2;
		}
#ifdef USE_C99_MATH
	else if(isnan(cws->mu))
		{
		// NaN in the solution
		ws->status = 3;
		}
#else
	else if(cws->mu != cws->mu)
		{
		// NaN in the solution
		ws->status = 3;
		}
#endif
	else
		{
		// normal return
		ws->status = 0;
		}

	return;

	}



void DENSE_QP_IPM_PREDICT(struct DENSE_QP *qp, struct DENSE_QP_SOL *qp_sol, struct DENSE_QP_IPM_ARG *arg, struct DENSE_QP_IPM_WS *ws)
	{

#if 0
	DENSE_QP_DIM_PRINT(qp->dim);
	DENSE_QP_PRINT(qp->dim, qp);
#endif

	int ii;

	struct CORE_QP_IPM_WORKSPACE *cws = ws->core_workspace;

	// arg to core workspace
	cws->lam_min = arg->lam_min;
	cws->t_min = arg->t_min;

	// alias qp vectors into qp_sol
	cws->v = qp_sol->v->pa;
	cws->pi = qp_sol->pi->pa;
	cws->lam = qp_sol->lam->pa;
	cws->t = qp_sol->t->pa;

	// alias members of qp_step
	ws->qp_step->dim = qp->dim;
	ws->qp_step->Hv = qp->Hv;
	ws->qp_step->A = qp->A;
	ws->qp_step->Ct = qp->Ct;
	ws->qp_step->Z = qp->Z;
	ws->qp_step->idxb = qp->idxb;
	ws->qp_step->idxs = qp->idxs;
	ws->qp_step->gz = ws->res->res_g;
	ws->qp_step->b = ws->res->res_b;
	ws->qp_step->d = ws->res->res_d;
	ws->qp_step->m = ws->res->res_m;


	// TODO ?

	// blasfeo alias for residuals
	struct STRVEC str_res_g;
	struct STRVEC str_res_b;
	struct STRVEC str_res_d;
	struct STRVEC str_res_m;
	str_res_g.m = cws->nv;
	str_res_b.m = cws->ne;
	str_res_d.m = cws->nc;
	str_res_m.m = cws->nc;
	str_res_g.pa = cws->res_g;
	str_res_b.pa = cws->res_b;
	str_res_d.pa = cws->res_d;
	str_res_m.pa = cws->res_m;

	REAL *qp_res = ws->qp_res;
	qp_res[0] = 0;
	qp_res[1] = 0;
	qp_res[2] = 0;
	qp_res[3] = 0;

#if 0
// compute residuals
DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);

// compute infinity norm of residuals
VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);

printf("\npredict\t%e\t%e\t%e\t%e\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3]);
#endif

	// load sol from bkp
	for(ii=0; ii<cws->nv; ii++)
		cws->v[ii] = cws->v_bkp[ii];
	for(ii=0; ii<cws->ne; ii++)
		cws->pi[ii] = cws->pi_bkp[ii];
	for(ii=0; ii<cws->nc; ii++)
		cws->lam[ii] = cws->lam_bkp[ii];
	for(ii=0; ii<cws->nc; ii++)
		cws->t[ii] = cws->t_bkp[ii];

	// TODO absolute formulation !!!!!

	// TODO robust formulation !!!!!

	// compute residuals
	DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);

	// compute infinity norm of residuals
	VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
	VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
	VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
	VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);

//printf("\npredict\t%e\t%e\t%e\t%e\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3]);

	// solve kkt
	SOLVE_KKT_STEP_DENSE_QP(ws->qp_step, ws->sol_step, arg, ws);

	// alpha TODO fix alpha=1 !!!!!
//	COMPUTE_ALPHA_QP(cws);
	cws->alpha = 1.0;

	//
	UPDATE_VAR_QP(cws);

	if(arg->comp_res_pred)
		{
		// compute residuals in exit
		DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);

		// compute infinity norm of residuals
		VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
		VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
		VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
		VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);
		}

//printf("\npredict\t%e\t%e\t%e\t%e\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3]);

	// TODO

	// do not change status

	return;

	}



void DENSE_QP_IPM_SENS(struct DENSE_QP *qp, struct DENSE_QP_SOL *qp_sol, struct DENSE_QP_IPM_ARG *arg, struct DENSE_QP_IPM_WS *ws)
	{

#if 0
	DENSE_QP_DIM_PRINT(qp->dim);
	DENSE_QP_PRINT(qp->dim, qp);
#endif

	int ii;

	struct CORE_QP_IPM_WORKSPACE *cws = ws->core_workspace;

	// arg to core workspace
	cws->lam_min = arg->lam_min;
	cws->t_min = arg->t_min;

	// alias qp vectors into qp_sol
	cws->v = qp_sol->v->pa;
	cws->pi = qp_sol->pi->pa;
	cws->lam = qp_sol->lam->pa;
	cws->t = qp_sol->t->pa;

	// load sol from bkp
	for(ii=0; ii<cws->nv; ii++)
		cws->v[ii] = cws->v_bkp[ii];
	for(ii=0; ii<cws->ne; ii++)
		cws->pi[ii] = cws->pi_bkp[ii];
	for(ii=0; ii<cws->nc; ii++)
		cws->lam[ii] = cws->lam_bkp[ii];
	for(ii=0; ii<cws->nc; ii++)
		cws->t[ii] = cws->t_bkp[ii];

	// solve kkt
	SOLVE_KKT_STEP_DENSE_QP(qp, qp_sol, arg, ws);

#if 0
	// alpha TODO fix alpha=1 !!!!!
//	COMPUTE_ALPHA_QP(cws);
	cws->alpha = 1.0;

	//
	UPDATE_VAR_QP(cws);

	if(arg->comp_res_pred)
		{
		// compute residuals in exit
		DENSE_QP_RES_COMPUTE(qp, qp_sol, ws->res, ws->res_workspace);

		// compute infinity norm of residuals
		VECNRM_INF(cws->nv, &str_res_g, 0, &qp_res[0]);
		VECNRM_INF(cws->ne, &str_res_b, 0, &qp_res[1]);
		VECNRM_INF(cws->nc, &str_res_d, 0, &qp_res[2]);
		VECNRM_INF(cws->nc, &str_res_m, 0, &qp_res[3]);
		}
#endif

//printf("\npredict\t%e\t%e\t%e\t%e\n", qp_res[0], qp_res[1], qp_res[2], qp_res[3]);

	// TODO

	// do not change status

	return;

	}
