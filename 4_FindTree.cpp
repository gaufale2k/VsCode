/*
	+ Tim kiem cay nhi phan
	+ Xuat cac node 2 con (L & R)
	+ Xuat cac node 1 con ( L || R )
	+ Xuat cac node la (NOT : R & L)
	+ Tim  min && max
	+ Xóa 1 node : 1 con, 2 con, node la
		Doi voi xoa node 2 con: Phai tim node the mang , thoa man dieu kien cay nhi phan
			+ Tìm node trái nhất của cây con phải (cây con phải của cái node cần xóa )
			+ Tìm node phải nhất của cây con trái (cây con trái của cái node cần xóa )
	............................
*/




#include<iostream>
using namespace std;

struct node
{
	int data; // dữ liệu của node ==> dữ liệu mà node sẽ lưu trữ
	struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
	struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;
// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; // cây rỗng
}
// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
	// nếu cây rỗng
	if (t == NULL)
	{
		NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
		p->data = x;// thêm dữ liệu x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node gốc <=> x chính là node gốc
	}
	else // cây có tồn tại phần tử
	{
		// nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
		}
		else if (t->data < x) // nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải
		{
			ThemNodeVaoCay(t->pRight, x); // duyệt qua phải để thêm phần tử x
		}
	}
}

// hàm xuất cây nhị phân theo LNR <=> xuất ra các phần tử từ bé đến lớn
void Duyet_LNR(TREE t)
{
	// nếu cây còn phần tử thì tiếp tục duyệt
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft); // duyệt qua trái
		cout << t->data << "  "; // xuất giá trị của node
		Duyet_LNR(t->pRight); // duyệt qua phải
	}
}




// Neu node đó tồn tại thì trả về node đó còn không trả về nULL

NODE * Search(TREE t, int x)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// Neu nho hon node goc - dequy ben trai
		if (x < t->data)
		{
			Search(t->pLeft, x);
		}
		else if (x > t->data)
		{
			Search(t->pRight, x);
		}
		else // Ton tai
		{
			return t; // tra ve node can tim kiem 
		}
	}
}



// Xuat cac node co 2 con
void Node_2(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
		{
			cout << t->data << " "; 
		}
		Node_2(t->pLeft);
		Node_2(t->pRight);
	}
}

// Xuat cac node co 1 con
void Node_1(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
		{
			cout << t->data << " ";
		}
		Node_1(t->pLeft);
		Node_1(t->pRight);
	}
}

// Xuat cac node la
void Node_la(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << " ";
		}
		Node_la(t->pLeft);
		Node_la(t->pRight);
	}
}


// Tim min && max
int TimMax(TREE t)
{
	if (t->pRight == NULL)
	{
		return t->data;
	}
	return TimMax(t->pRight);
}

int TimMin(TREE t)
{
	if (t->pLeft == NULL)
	{
		return t->data;
	}
	return TimMin(t->pLeft);
}

// Ham tim node the mang
void Timnodethe(TREE &X, TREE &Y) // NODE *Y = t->pRight
{


	// CACH 1 : tRAI NHAT CUA CAY CON PHAI
	//// duyet sang node trai nhat
	//if (Y->pLeft != NULL)
	//{
	//	Timnodethe(X, Y->pLeft); // Duyet tim ra node trai nhat
	//}
	//else  // Tim ra  node trai nhat roi
	//{
	//	X->data = Y->data; // Ban chat ko xoa node can xoa, ma di xoa node the mang cua no, cap nhat data node can xosa la 
	//					   // data node the mang
	//	X = Y; // Node X la  node se xoa sau nay la node the mang, cho X tro den node the mang
	//			// Sau nay xoa node X
	//	Y = Y->pRight; // Ban chat la gan 
	//	// Y đến thời điểm này đang là node trai ngoài cùng, và do nó là node trái ngoài cùng lên nó tới NULL.
	//	// Hau nói cách khác Y->pRight = NULL\, ta xóa node thế mạng là node trái ngoài cùng đi thì cái liên kêt
	//	// giữa node trước đó với node này phải được đảm bảo. Vì thế khi Y phải trỏ tới NULL. Thời điểm này nó
	//	// Như nhánh trái của Node trên cái node bên trái ngoài cùng bị xóa và nó trỏ tới NULL 
	//	// CAP NHAT LAI MỐI LIÊN KẾT CỦA NODE CHA CỦA NODE THẾ MẠNG (MÀ CHÚNG TA SẼ XÓA)
	//}



	// CACH 2 : Node phai nhat cua cay con trai
		//// duyet sang node trai nhat
	if (Y->pRight != NULL)
	{
		Timnodethe(X, Y->pRight); // Duyet tim ra node trai nhat
	}
	else  // Tim ra  node phai nhat roi
	{
		X->data = Y->data; // Ban chat ko xoa node can xoa, ma di xoa node the mang cua no, cap nhat data node can xosa la 
						   // data node the mang
		X = Y; // Node X la  node se xoa sau nay la node the mang, cho X tro den node the mang
				// Sau nay xoa node X
		Y = Y->pLeft; // Ban chat la gan 
		// Y đến thời điểm này đang là node trai ngoài cùng, và do nó là node trái ngoài cùng lên nó tới NULL.
		// Hau nói cách khác Y->pRight = NULL\, ta xóa node thế mạng là node trái ngoài cùng đi thì cái liên kêt
		// giữa node trước đó với node này phải được đảm bảo. Vì thế khi Y phải trỏ tới NULL. Thời điểm này nó
		// Như nhánh trái của Node trên cái node bên trái ngoài cùng bị xóa và nó trỏ tới NULL 
		// CAP NHAT LAI MỐI LIÊN KẾT CỦA NODE CHA CỦA NODE THẾ MẠNG (MÀ CHÚNG TA SẼ XÓA)
	}



}


// Xoa node 1 con và node la
void XoaNode(TREE &t, int data)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		// Neu data nho hon node goc
		if (t->data > data)
		{
			XoaNode(t->pLeft, data);
		}
		else if (t->data < data)
		{
			XoaNode(t->pRight, data);
		}
		else
		{
			NODE *temp = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else // node can xoa la node co  2 con
			{
				// Cach 1: Tim node trai nhat cay con phai
				//Timnodethe(temp, t->pRight); 

				// Cach 2: Tim node phai nhat cua cay ben trai cua node can xoa

				Timnodethe(temp, t->pLeft);
			}
			delete temp;
		}
	}
}








// hàm nhập dữ liệu
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Duyet cay LNR";
		cout << "\n3. Tim kiem phan tu trong binary tree";
		cout << "\n4. Xuat node co 2 con";
		cout << "\n5. Xuat node co 1 con";
		cout << "\n6. Xuat cac node la ";
		cout << "\n7. Tim min max ";
		cout << "\n8. Xoa 1 node ";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 8)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO LNR \n";
			Duyet_LNR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "\n\t\t Tim kiem trong cay nhi phan\n";
			int x;
			cout << "\n Nhap vao phan tu can kiem tra tim kiem :  ";
			cin >> x;
			NODE *p = Search(t, x);
			if (p == NULL)
			{
				cout << "\n Khong ton tai trong cay nhi phan !";
			}
			else
			{
				cout << "\n Ton tai trong cay nhi phan  !";
			}

			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\n Node co 2 con la :   ";
			Node_2(t); 
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n Node co 1 con la :   ";
			Node_1(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n Xuat cac node la :   ";
			Node_la(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n Xuat " <<"min = "<< TimMin(t) << "max = " << TimMax(t);
			system("pause");
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\n Xoa  node :   ";
			cin >> x;
			XoaNode(t, x);
			system("pause");
		}
		else
		{
			break;
		}
	}

}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}