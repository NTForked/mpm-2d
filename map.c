/**
    \file interpolate.c
    \author Sachith Dunatunga
    \date 04.06.12

    mpm_2d -- An implementation of the Material Point Method in 2D.
*/
#include "process.h"

#define PI 3.14159

#define SF_WARNING4(tok) \
    if (*tok > 1 || *tok < 0) { \
        fprintf(stderr, "warning, " #tok " = %g\n", *tok); \
    }

#define SF_WARNING(tok) \
    if (*tok > 1 || *tok < -1) { \
        fprintf(stderr, "warning, " #tok " = %g\n", *tok); \
    }

/* IMPORTANT: Does not clear nodal quantites before accumulating! */
/*---Maps scalars of type double to nodes. Uses shape functions.--------------*/
void map_particles_to_nodes_doublescalar(job_t *job,
    size_t node_field_offset, size_t particle_field_offset)
{
    size_t i, j;
    double *ndata;
    double *pdata;
    int *n_idx;
    double s[NODES_PER_ELEMENT];

    for (i = 0; i < job->num_particles; i++) {
        if (job->particles[i].active == 0) {
            continue;
        }

        /* 
            Bit of a hack, but should work. If C had reflection, this wouldn't be
            an issue.
        */
        pdata = (double *)((char *)&(job->particles[i]) + particle_field_offset);
        n_idx = job->elements[job->in_element[i]].nodes;

        /* Really gotta clean the organization up, but use this for now. */
        s[0] = job->h1[i];
        s[1] = job->h2[i];
        s[2] = job->h3[i];
        s[3] = job->h4[i];

        for (j = 0; j < NODES_PER_ELEMENT; j++) {
            ndata = (double *)((char *)&(job->nodes[n_idx[j]]) + node_field_offset);
            *ndata += s[j] * (*pdata);
        }
    }

    return;
}
/*----------------------------------------------------------------------------*/
/*---Accumulates scalars of type double to nodes. Inner loop of the map.------*/
void accumulate_p_to_n_doublescalar(node_t *nodes,
    size_t node_field_offset, int *nodelist, double *sfvalues, double pdata)
{
/*    size_t i, j;*/
/*    double *ndata;*/
/*    double *pdata;*/
/*    int *n_idx;*/
/*    double s[NODES_PER_ELEMENT];*/

/*    for (i = 0; i < job->num_particles; i++) {*/
/*        if (job->particles[i].active == 0) {*/
/*            continue;*/
/*        }*/

        /* 
            Bit of a hack, but should work. If C had reflection, this wouldn't be
            an issue.
        */
/*        pdata = (double *)((char *)&(job->particles[i]) + particle_field_offset);*/
/*        n_idx = job->elements[job->in_element[i]].nodes;*/

        /* Really gotta clean the organization up, but use this for now. */
/*        s[0] = job->h1[i];*/
/*        s[1] = job->h2[i];*/
/*        s[2] = job->h3[i];*/
/*        s[3] = job->h4[i];*/

/*        for (j = 0; j < NODES_PER_ELEMENT; j++) {*/
/*            ndata = (double *)((char *)&(job->nodes[n_idx[j]]) + node_field_offset);*/
/*            *ndata += s[j] * (*pdata);*/
/*        }*/
/*    }*/

    return;
}
/*----------------------------------------------------------------------------*/

