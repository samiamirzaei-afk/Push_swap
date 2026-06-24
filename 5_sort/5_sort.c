/*
	
	1- if a[0] > a[1], swap
	2- if smallest is at a[0] up to 2 numbers, pb
	3- bring the currect smalest to a[0]  

   	4 1 5 3 2 SA
	1 4 5 3 2 PB
	4 5 3 2 (1) SA
	5 4 3 2 (1) RA
	2 5 4 3 (1) PB
	5 4 3 (2 1) SA
	4 5 3 (2 1) rra
	3 4 5 (2 1) PA
	PA
	1 2 3 4 5



	5 4 3 2 1 SA
	4 5 3 2 1 RA
	1 4 5 3 2 PB
	4 5 3 2 (1) RA
	2 4 5 3 (1) PB
	4 5 3 (2 1) RA
	3 4 5 (2 1) PA
	PA

	5 1 4 2 3 SA
	1 5 4 2 3 PB
	5 4 2 3 (1) SA
	4 5 2 3 (1) RA
	3 4 5 2 (1) RA
	2 3 4 5 (1)
	4 5 3 2 (1) RA
	2 3 4 5 (1) PB
	1 2 3 4 5
