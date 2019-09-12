#include "pch.h"
#include "stats.h"


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R=new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete R;
	delete L;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void sortarray(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		sortarray(arr, l, m);
		sortarray(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void setstatarray(int st[])
{
	for (int i = 0; i < 6; i++) {
		st[i]=rand() % 20 + 7;
	}
	for (int i = 0; i < 6; i++) {
		while (st[i] > 18) {
			st[i] = rand() % 20 + 7;
		}
	}
	sortarray(st, 0,5);
	return;
}

void statbreakdown(int stat[], int c) {
	switch(c){
	case 1: //Paladin choice
		cout << "STR: "<<stat[0] << "	DEX: " << stat[4] << "	CON: " << stat[1] << "	WIS: " 
			<< stat[2] << "	INT: " << stat[5] << "	CHA: " << stat[3] << "\n";
		cout << "A paladin is a holy knight, crusading in the name of good and order. Wielding a mighty sword, "
			"they are a force to be reckoned with, serving as beacons for their allies"
			"within the chaos of battle.\n";
		cout << "SPECIAL: You can detect evil afoot.\n";
		break;
	case 2:  //rougue choice
		cout << "STR: " << stat[4] << "	DEX: " << stat[0] << "	CON: " << stat[2] << "	WIS: "
			<< stat[3] << "	INT: " << stat[5] << "	CHA: " << stat[1] << "\n";
		cout << "Ever just one step ahead of danger, rogues bank on their cunning, "
			"skill, and charm to bend fate to their favor. Never knowing what to expect, "
			"they prepare for everything, becoming masters of a wide variety of skills, training themselves to be "
			"adept manipulators, agile acrobats, shadowy stalkers, or masters of any of dozens of other professions or talents."
			"Rogues excel at moving about unseen and catching foes unaware, and tend to avoid head-to-head combat.\n";
			cout << "SPECIAL: If you flank an opponent, you deal double damage.\n";
		break;
	case 3:  //ranger choice
		cout << "STR: " << stat[1] << "	DEX: " << stat[0] << "	CON: " << stat[4] << "	WIS: "
			<< stat[2] << "	INT: " << stat[3] << "	CHA: " << stat[5] << "\n";
		cout << "SPECIAL: You can track any manner of footprints back to the source.\n";
		break;
	case 4: //monk choice
		cout << "STR: " << stat[0] << "	DEX: " << stat[2] << "	CON: " << stat[3] << "	WIS: "
			<< stat[4] << "	INT: " << stat[1] << "	CHA: " << stat[5] << "\n";
		break;
	case 5: //wizard choice
		cout << "STR: " << stat[5] << "	DEX: " << stat[2] << "	CON: " << stat[3] << "	WIS: "
			<< stat[1] << "	INT: " << stat[0] << "	CHA: " << stat[4] << "\n";
		break;
	}
}
