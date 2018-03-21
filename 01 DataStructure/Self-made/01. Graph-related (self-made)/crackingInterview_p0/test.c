
Test(sf_memsuite_student, alloc_no_splitting, .init = sf_mem_init, .fini = sf_mem_fini) {

    sf_errno = 0;
	double *x = sf_malloc(PAGE_SZ-32);

	*x = 3.5;
	free_list *fl = &seg_free_list[0];
	cr_assert_null(fl->head, "There should be no free block!!!");
	cr_assert(sf_errno == 0, "sf_errno is not zero!!!");
	cr_assert(get_heap_start() + PAGE_SZ == get_heap_end(), "Allocated more than necessary!!!");
}

Test(sf_memsuite_student, malloc_invalid_request, .init = sf_mem_init, .fini = sf_mem_fini) {
	sf_errno = 0;
	double *x = sf_malloc(PAGE_SZ * 10);
	cr_assert_null(x);
	cr_assert(sf_errno == EINVAL, "sf_errno is not EINVAL!");
}


Test(sf_memsuite_student, realloc_larger_block_but_same_blocksize, .init = sf_mem_init, .fini = sf_mem_fini) {

	sf_errno = 0;
	void *x = sf_malloc(sizeof(int));

	sf_header *header = (sf_header*)((char*)x - 8);
	free_list *fl = &seg_free_list[find_list_index_from_size(PAGE_SZ - (header->block_size << 4))];

	x = sf_realloc(x, sizeof(int) + 1);

	free_list *fl2 = &seg_free_list[3];
	cr_assert(fl== fl2, "there should be no size change in free block");
	cr_assert(get_heap_start() + PAGE_SZ == get_heap_end(), "Allocated more than necessary!");

}

Test(sf_memsuite_student, malloc_zero, .init = sf_mem_init, .fini = sf_mem_fini) {
	sf_errno = 0;
	double *x = sf_malloc(0);
	cr_assert_null(x);
	cr_assert(sf_errno == EINVAL, "sf_errno is not EINVAL!");
}

Test(sf_memsuite, Free_block_check_footer_values, .init = sf_mem_init, .fini = sf_mem_fini) {
  void *x = sf_malloc(2*sizeof(double));
  sf_free(x);
  x = (char*)x - 8;
  sf_header *cur_header = (sf_header *) x;
  sf_footer *cur_footer = (sf_footer *) ((char*)x + (cur_header->block_size << 4) - 8);
  cr_assert(cur_footer->allocated == 0, "Allocated bit in the footer is not 0!\n");
}

