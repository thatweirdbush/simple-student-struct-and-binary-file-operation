/*****************************************
// Implement: Linked List
******************************************/
#include <iostream>

using namespace std;

struct Data {
	int x;
};

struct Node {
	Data info;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

// Hàm tạo Node mới
Node* CreateNode(Data value) {
	Node* p = new Node();
	if (p != nullptr) {
		p->info = value;
		p->pNext = nullptr;
	}
	return p;
}

// Hàm tạo DSLK rỗng
void initList(List& l) {
	l.pHead = l.pTail = nullptr;
}

// Hàm so sánh hai dữ liệu
// Đầu vào: 2 dữ liệu cần so sánh (a, b)
// Đầu ra: 0 nếu a = b, 1 nếu a > b, -1 nếu a < b
int CompareData(Data a, Data b) {
	if (a.x == b.x) {
		return 0;
	}
	else if (a.x > b.x) {
		return 1;
	}
	else {
		return -1;
	}
}

// Hàm tìm node đầu tiên trong DSLK có dữ liệu cho trước
// Đầu vào: DSLK (l), dữ liệu cần tìm (info)
// Đầu ra: Con trỏ đến node tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	Node* p = l.pHead;
	while (p == NULL)
		return p;
	while (p != NULL && CompareData(p->info, info) != 0)
		p = p->pNext;
	return p;
}

// Hàm tìm node có chỉ số (bắt đầu từ 8) cho trước
// Đầu vào: DSLK (l), chỉ số của node cần lấy (index)
// Đầu ra: Con trỏ đến node tìm được(trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	Node* p = l.pHead;
	int i = 0;
	while (p != nullptr && i < index)
	{
		p = p->pNext;
		i++;
	}
	return p;
}

// Hàm xác định vị trí của một node cho trước trong DSLK cho trước
// Đầu vào: DSLK (l), con trỏ đến node cần xác định vị trí (pNode)
// Đầu ra: Thứ tự của node cho trước(trả về - 1 nếu node này không có trong	DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	if (l.pHead == NULL)
		return -1;
	Node* p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p == pNode)
			return i;
		p = p->pNext;
		++i;
	}
	return -1;
}

// Hàm xác định con trỏ đến node đứng trước của một node cho trước trong DSLK
// Đầu vào: DSLK (l), con trỏ đến node cho trước (pNode)
// Đầu ra: Con trỏ đến node tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	Node* p = l.pHead;
	Node* pOld = NULL;
	while (p != NULL)
	{
		if (p == pNode)
			return pOld;
		pOld = p;
		p = p->pNext;
	}
	return NULL;
}

// Hàm chèn một node cho trước vào đầu DSLK
// Đầu vào: Tham chiếu đến DSLK(l), con trỏ đến node cần chèn(pNewNode)
// Đầu ra: Không có
void AddHead(List& l, Node* pNewNode) {
	pNewNode->pNext = l.pHead;
	l.pHead = pNewNode;
	if (l.pTail == NULL)
		l.pTail = l.pHead;
}

// Hàm chèn một node có dữ liệu cho trước vào đầu DSLK
// Đầu vào: Tham chiếu đến DSLK(l), dữ liệu của node cần chèn(info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info) {
	Node* p = CreateNode(info);
	if (p != NULL) {
		AddHead(l, p);
	}
	return p;
}

// Hàm chèn một node cho trước vào cuối DSLK
// Đầu vào: Tham chiếu đến DSLK(l), con trỏ đến node cần chèn(pNewNode)
// Đầu ra: Không có
void AddTail(List& l, Node* pNewNode) {
	if (l.pTail == NULL) {
		l.pHead = pNewNode;
		l.pTail = pNewNode;
	}
	else {
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
	l.pTail->pNext = NULL;
}

// Hàm chèn một node có dữ liệu cho trước vào cuối DSLK
// Đầu vào: Tham chiếu đến DSLK(l), dữ liệu của node cần chèn(info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info) {
	Node* p = CreateNode(info);
	if (p != NULL) {
		AddTail(l, p);
	}
	return p;
}

// Hàm chèn một node cho trước vào sau một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK(l), con trỏ đến node cho trước(q), con trỏ đến node cần chèn(pNewNode)
// Đầu ra: Không có
void AddAfter(List& l, Node* q, Node* pNewNode) {
	if (q == NULL || pNewNode == NULL)
		return;
	pNewNode->pNext = q->pNext;
	q->pNext = pNewNode;
	if (l.pTail == q)
		l.pTail = pNewNode;
}

// Hàm chèn một node có dữ liệu cho trước vào sau một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK(l), con trỏ đến node cho trước(q), con trỏ đến node cần chèn(pNewNode)
// Đầu ra: Không có
Node* AddAfter(List& l, Node* q, Data info) {
	if (q == NULL)
		return NULL;
	Node* p = CreateNode(info);
	if (p != NULL) {
		AddAfter(l, q, p);
	}
	if (q->pNext != p)
		return NULL;
	return p;
}

// Hàm chèn một node cho trước vào trước một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), con trỏ đến node cần chèn(pNewNode)
// Đầu ra: Không có
void AddBefore(List& l, Node* q, Node* pNewNode) {
	if (q == NULL || pNewNode == NULL)
		return;
	if (q == l.pHead) {
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
		return;
	}
	Node* p = GetPreviousNodePointer(l, q);
	if (p == NULL)
		return;
	p->pNext = pNewNode;
	pNewNode->pNext = q;
}

// Hàm chèn một node có dữ liệu cho trước vào trước một node khác cho trước
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cho trước (q), dữ liệu của node cần chèn(info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	if (q == NULL)
		return NULL;
	Node* p = CreateNode(info);
	if (p != NULL)
	{
		AddBefore(l, q, p);
		if (p->pNext != q)
			return NULL;
	}
	return p;
}

// Hàm chèn một node cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến node cần chèn (pNewNode)
// Đầu ra: Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	if (pNewNode == NULL)
		return;
	Node* p = l.pHead;
	while (p != NULL) {
		if (CompareData(p->info, pNewNode->info) > -1) {
			AddBefore(l, p, pNewNode);
			return;
		}
	}
	if (p == NULL && l.pTail == NULL)
	{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// Hàm chèn một node có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của node cần chèn (info)
// Đầu ra: Con trỏ đến node được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	Node* p = CreateNode(info);
	if (p != NULL) {
		AddAscendingList(l, p);
	}
	return p;
}

// Hàm hủy một node đầu DSLK
// Đầu vào: Tham chiếu đến DSLK(l)
// Đầu ra: Dữ liệu của node bị xóa
Data* RemoveHead(List& l) {
	if (l.pHead == NULL)
		return nullptr;
	Data* kq = new Data;
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	if (l.pHead == NULL)
		l.pTail = NULL;
	kq->x = p->info.x;
	delete p;
	return kq;
}

// Hàm hủy một node cuối DSLK
// Đầu vào: Tham chiếu đến DSLK(l)
// Đầu ra: Dữ liệu của node bị xóa
Data* RemoveTail(List& l) {
	if (l.pHead == NULL)
		return nullptr;
	Data* kq = new Data;
	Node* p = l.pHead;
	Node* q = NULL;
	while (p != l.pTail) {
		q = p;
		p = p->pNext;
	}
	if (q != NULL)
		q->pNext = NULL;
	else
		l.pHead = NULL;
	kq->x = p->info.x;
	delete p;
	l.pTail = q;
	return kq;
}

// Hàm hủy một node đứng sau một node cho trước trong DSLK
// Đầu vào: Tham chiếu đến DSLK(l), con trỏ đến node cho trước(q)
// Đầu ra: Không có
Data* RemoveAfter(List& l, Node* q) {
	if (q == NULL)
		return RemoveHead(l);
	Data* kq = new Data;
	Node* p = l.pHead;
	while (p != NULL) {
		if (p == q)
			break;
		p = p->pNext;
	}
	if (p != NULL) {
		p = q->pNext;
		if (p != NULL) {
			q->pNext = p->pNext;
			kq->x = p->info.x;
			delete p;
			if (q->pNext == NULL)
				l.pTail = q;
		}
	}
	return kq;
}

// Hàm hủy một node có dữ liệu cho trước trong DSLK
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của node cần xóa (info)
// Đầu ra: Tìm thấy node có dữ liệu info hay không (true/false)
bool RemoveNode(List& l, Data info) {
	Node* p = GetNodePointer(l, info);
	if (p == NULL)
		return false;
	Node* q = GetPreviousNodePointer(l, p);
	if (q == NULL)
	{
		l.pHead = p->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = l.pHead;
		return true;
	}
	q->pNext = p->pNext;
	delete p;
	if (q->pNext == NULL)
		l.pTail = q;
	return true;
}

// Hàm hủy DSLK
void DeleteList(List* l) {
	Node* p = l->pHead;
	while (p != NULL) {
		Node* q = p;
		p = p->pNext;
		delete q;
	}
	l->pHead = l->pTail = NULL;
}

// Hàm xuất DSLK
void PrintList(List l) {
	for (Node* p = l.pHead; p != nullptr; p = p->pNext) {
		cout << p->info.x << " ";
	}
	cout << endl;
}

// Hàm sắp xếp DSLK tăng dần
void SortList(List& l) {
	Node* p = l.pHead;
	while (p != NULL) {
		Node* q = p->pNext;
		while (q != NULL) {
			if (CompareData(p->info, q->info) > 0) {
				Data temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
			q = q->pNext;
		}
		p = p->pNext;
	}
}

// Hàm chia DSLK thành 2 DSLK con
void SplitList(List l, List& l1, List& l2) {
	initList(l1);
	initList(l2);
	Node* p = l.pHead;
	while (p != NULL) {
		AddTail(l1, p->info);
		p = p->pNext;
		if (p != NULL) {
			AddTail(l2, p->info);
			p = p->pNext;
		}
	}
}

// Hàm chia DSLK thành 2 DSLK con dựa vào con trỏ p làm mốc cho trước
void SplitList(List l, List& l1, List& l2, Node* p) {
	initList(l1);
	initList(l2);
	Node* q = l.pHead;
	while (q != NULL) {
		if (q == p)
			break;
		AddTail(l1, q->info);
		q = q->pNext;
	}
	//q = q->pNext;
	while (q != NULL) {
		AddTail(l2, q->info);
		q = q->pNext;
	}
}

// Thử nghiệm tất cả các hàm đã cài đặt
int main() {
	List l;
	initList(l);

	// Phát sinh ngẫu nhiên DSLK
	srand((unsigned)time(NULL));
	int n = 10 + rand() % 91;
	for (int i = 0; i < n; i++) {
		Data data;
		data.x = -50 + rand() % 101;
		AddTail(l, data);
	}
	cout << "KQ tu bai 01...\nDSLK:\n";
	PrintList(l);

	// Thêm node vào đầu DSLK
	Data data;
	data.x = 100;
	AddHead(l, data);
	cout << "\nThem node dau DSLK: " << l.pHead->info.x << endl;
	PrintList(l);

	// Thêm node vào cuối DSLK
	data.x = 200;
	AddTail(l, data);
	cout << "\nThem node cuoi DSLK: " << l.pTail->info.x << endl;
	PrintList(l);

	// Thêm node vào sau node đầu tiên
	data.x = 300;
	Node* p = GetNodePointer(l, l.pHead->info);
	AddAfter(l, p, data);
	cout << "\nThem node sau node dau tien: " << p->pNext->info.x << endl;
	PrintList(l);

	// Thêm node vào trước node cuối cùng
	data.x = 400;
	p = GetNodePointer(l, l.pTail->info);
	AddBefore(l, p, data);
	cout << "\nThem node truoc node cuoi cung: " << data.x << endl;
	PrintList(l);

	// Thêm node vào DSLK sao cho DSLK vẫn tăng dần
	data.x = 50;
	AddAscendingList(l, data);
	cout << "\nThem node sao cho DSLK van tang dan: " << data.x << endl;
	PrintList(l);

	// Xóa node đầu DSLK
	Data* kq = RemoveHead(l);
	if (kq != nullptr) {
		cout << "\nNode dau DSLK bi xoa: " << kq->x << endl;
		delete kq;
		kq = nullptr;
	}
	PrintList(l);

	// Xóa node cuối DSLK
	kq = RemoveTail(l);
	if (kq != nullptr) {
		cout << "\nNode cuoi DSLK bi xoa: " << kq->x << endl;
		delete kq;
		kq = nullptr;
	}
	PrintList(l);

	// Xóa node đứng sau node đầu tiên
	p = GetNodePointer(l, l.pHead->info);
	kq = RemoveAfter(l, p);
	if (kq != nullptr) {
		cout << "\nNode sau node dau DSLK bi xoa: " << kq->x << endl;
		delete kq;
		kq = nullptr;
	}
	PrintList(l);

	// Xóa node có dữ liệu cho trước
	data.x = 400;
	if (RemoveNode(l, data)) {
		cout << "\nNode co du lieu " << data.x << " bi xoa:" << endl;
	}
	else {
		cout << "\nKhong tim thay node co du lieu " << data.x << endl;
	}
	PrintList(l);

	// Sắp xếp DSLK tăng dần
	SortList(l);
	cout << "\nDSLK sau khi sap xep tang dan:\n";
	PrintList(l);

	// Chia DSLK thành 2 DSLK con
	List l1, l2;
	SplitList(l, l1, l2);
	cout << "\nChia DSLK thanh 2 DSLK con:";
	cout << "\nDSLK 1:\n";
	PrintList(l1);
	cout << "\nDSLK 2:\n";
	PrintList(l2);

	// Chia DSLK thành 2 DSLK con dựa vào con trỏ p làm mốc cho trước
	List l3, l4;
	int random = rand() % n;
	p = GetNodePointer(l, random);
	SplitList(l, l3, l4, p);
	cout << "\nChia DSLK thanh 2 DSLK con dua vao con tro p = " << p->info.x << " lam moc cho truoc: ";
	cout << "\nDSLK 1:\n";
	PrintList(l3);
	cout << "\nDSLK 2:\n";
	PrintList(l4);

	// Xóa các DSLK
	cout << "\nXoa cac DSLK...\n";
	DeleteList(&l);
	DeleteList(&l1);
	DeleteList(&l2);
	DeleteList(&l3);
	DeleteList(&l4);

	system("pause");
	return 0;
}