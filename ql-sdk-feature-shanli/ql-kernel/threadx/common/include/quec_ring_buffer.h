#ifndef _QUEC_RING_BUFFER_H_
#define _QUEC_RING_BUFFER_H_

#ifdef __cplusplus
	 extern "C" {
#endif

typedef struct quec_ring_buf_struct {
    unsigned int size;
    unsigned int  rpos;
    unsigned int  wpos;
    unsigned char *data;
}quec_ring_buf_t;

unsigned int __kfifo_rb_write(quec_ring_buf_t *rb, unsigned char *data, unsigned int len);

unsigned int __kfifo_rb_read(quec_ring_buf_t *rb, unsigned char *data, unsigned int len);

quec_ring_buf_t *__kfifo_rb_create(unsigned int size);

void __kfifo_rb_destroy(quec_ring_buf_t **rb);

int __kfifo_rb_init(void);

unsigned int __kfifo_rb_is_empty(quec_ring_buf_t *rb);

unsigned int __kfifo_rb_is_full(quec_ring_buf_t *rb);

unsigned int __kfifo_rb_data_len(quec_ring_buf_t *rb);

unsigned int __kfifo_rb_free_space(quec_ring_buf_t *rb);



#ifdef __cplusplus
	} /*"C" */
#endif

#endif

