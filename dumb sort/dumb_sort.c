/*
 * 1- if a[0] > a[1] by just one, SA		 2 1 4 3 => 1 2 4 3
 * 2- if a[0] < a[n] by just one, RRA 	 	 2 4 1 3 => 3 2 4 1
 * 3- if a[0] < a[n] by 2 or more, RRA, PB	 2 1 3 4 => 4 2 1 3 => 2 1 3 (4)
 * 4- if a[0] < a[1] by 2 or more but a[1]
 * is less than a[n], SA	 		 1 3 2 4 => 3 1 2 4
 * 5- if a[0] > a[n] by just one, RRA 		 6 4 1 5 => 5 6 4 1
 * 6- if a[0] > a[n] by 2 or more, 
 * but a[0] > a[1] RA				 6 4 1 5 => 5 6 4 1
 * 	1 4 5 => 4 1 5 => 5 4 1
*/
// 5 2 3 4 1
/*

	 6 4 1 5 => 5 6 4 1	RRA
	 5 6 4 1 => 1 5 6 4	RRA
	 1 5 6 4 => 4 1 5 6	RRA
	 4 1 5 6 => 1 4 5 6 	SA
*/


	8 9 1 4 3 6 2	RA	
	9 1 4 3 6 2 8	RA
	1 4 3 6 2 8 9	
