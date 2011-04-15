#ifndef _LIB_FPA_H
#define _LIB_FPA_H

/* Helper functions for Fixed-Point Arithmetic */

#define FPA_59_60       16110
#define FPA_1_60        273
#define FPA_F           16384

int64_t
conv_to_fpa (int64_t num, int64_t denom )
{
    return (num * FPA_F)/denom;
}

int
conv_from_fpa_nearest (int64_t fpa)
{
    return (fpa + (FPA_F / 2)) / FPA_F;
}

int64_t
mult_fpa_integer (int64_t fpa, int64_t integer)
{
    return fpa * integer;
}

int64_t
mult_fpa_fpa (int64_t fpa1, int64_t fpa2)
{
    return (fpa1 * fpa2 / FPA_F);
}

int64_t
div_fpa_integer (int64_t fpa, int64_t integer)
{
    return fpa / integer;
}

int64_t
div_fpa_fpa (int64_t fpa1, int64_t fpa2)
{
    return (fpa1 * FPA_F / fpa2);
}

int64_t
sub_fpa_integer (int64_t fpa, int64_t integer)
{
    return fpa - integer * FPA_F;
}

int64_t
sub_fpa_fpa (int64_t fpa1, int64_t fpa2)
{
    return fpa1 - fpa2;
}

int64_t
add_fpa_integer (int64_t fpa, int64_t integer)
{
    return fpa + integer * FPA_F;
}

int64_t
add_fpa_fpa (int64_t fpa1, int64_t fpa2)
{
    return fpa1 + fpa2;
}

int64_t
load_calc (int64_t load_in)
{
  return (16110 * load_in) / 16384 + 273 * ready_threads;
}

int64_t
recent_cpu_calc (int64_t rcpu, int64_t load_av, int nice_in)
{
  return (2 * load_av)/(2 * load_av + 1) * rcpu + nice_in;
}

#endif /* _LIB_FPA_H */
