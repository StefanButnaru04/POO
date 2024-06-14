/*#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Index, ReturnareIndex)
{
	Sortari<int> a(3, 2, 8, 6);

	int i;
	int n=3;
	for (i = 0;i < n;i++)
		cout << a.ElemDePePozitia(i) << " ";

	EXPECT_EQ(a.ElemDePePozitia(1), 8);
	EXPECT_TRUE(a.ElemDePePozitia(0) != 5);

}

TEST(Sortari, bubble)
{
	Sortari<int> a(3,2,8,6);

	//a->Sortari(5,2,7,8,6,5);
	a.BubbleSort(false);
	EXPECT_EQ(a.ElemDePePozitia(0), 8);

}

TEST(Sortari, NrElem)
{
	Sortari<int> a(3, 2, 8, 6);
	int n = 3;
	EXPECT_EQ(a.NrElemente(), n);
	EXPECT_TRUE(a.NrElemente() != n * 2);

}

TEST(Sortari, bubble2)
{
	Sortari<int> a(3, 2, 8, 6);
	a.BubbleSort(true);
	EXPECT_EQ(a.ElemDePePozitia(0), 2);


}*/

#include "pch.h"
#include <iostream>

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(Index, ReturnareElem)
{
	Sort<int> a(3,2,4,1);
	int i;
	int n = 3;
	/*for (i = 0;i < n;i++)
		cout << a.ReturnElem(i) << " ";
		*/
	EXPECT_EQ(a.GetElementFromIndex(1), 8);
	EXPECT_TRUE(a.GetElementFromIndex(0) != 5);

}

TEST(Sortari, bubble)
{
	Sort<int> a(3, 2, 8, 6);

	//a->Sortari(5,2,7,8,6,5);
	a.BubbleSort(true);
	EXPECT_EQ(a.GetElementFromIndex(0), 2);
	EXPECT_TRUE(a.GetElementFromIndex(1) == 6);
	EXPECT_EQ(a.GetElementFromIndex(2), 8);

}

TEST(Sortari, NrElem)
{
	Sort<int> a(3, 2, 8, 6);
	int n = 3;
	EXPECT_EQ(a.GetElementsCount(), n);
	EXPECT_TRUE(a.GetElementsCount() != n * 2);

}

TEST(Sortari, bubble2)
{
	Sort<int> a(3, 2, 8, 6);
	a.BubbleSort(false);
	EXPECT_EQ(a.GetElementFromIndex(0), 8);
	EXPECT_TRUE(a.GetElementFromIndex(1) == 6);
    EXPECT_EQ(a.GetElementFromIndex(2), 2);


}

TEST(Sortari, insert)
{
	Sort<int> a(3, 2, 8, 6);
	a.InsertSort(true);
	EXPECT_EQ(a.GetElementFromIndex(2), 8);

}