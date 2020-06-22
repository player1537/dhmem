#ifndef _COMMON_H_
#define _COMMON_H_

/** outputs **/

struct e_out_data {
    float a, b, c;
    float x;
    float y;
    float yp;
};

struct s_out_data {
    float a, b, c;
    float x;
};

/** inputs **/

//typedef e_out_data e_out_data;
typedef s_out_data e_in_data;

//typedef s_out_data s_out_data;
typedef e_out_data s_in_data;

typedef e_out_data v_in_data;

#endif /* _COMMON_H_ */
