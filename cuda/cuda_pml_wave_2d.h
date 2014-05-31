#ifndef Cuda_2D_PML_WAVE_SOLVER_H
#define Cuda_2D_PML_WAVE_SOLVER_H

#include "../defines.h"

struct Cuda_PML_Wave_2d_sim_data_t;

typedef Cuda_PML_Wave_2d_sim_data_t * Cuda_PML_Wave_2d_t;

Cuda_PML_Wave_2d_t wave_sim_init(Number_t xmin, Number_t ymin,
								Number_t xmax, Number_t ymax,
								Number_t c, Number_t dt,
								int nx, int ny,
								Number_t (*init_function)(Number_t, Number_t, void *),
								void * ctx,
								Number_t pml_width,
								Number_t pml_strength);

void wave_sim_free(Cuda_PML_Wave_2d_t wave);

Number_t wave_sim_get_x(Cuda_PML_Wave_2d_t wave, int j);
Number_t wave_sim_get_y(Cuda_PML_Wave_2d_t wave, int i);

//Acessing element:
// u[j + i*(nx+2)]
// i -> y, j->x

void wave_sim_step(Cuda_PML_Wave_2d_t wave);
void wave_sim_apply_boundary(Cuda_PML_Wave_2d_t wave);

Number_t * wave_sim_get_u(Cuda_PML_Wave_2d_t wave);

#endif 