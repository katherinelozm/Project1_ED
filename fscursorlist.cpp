/* struct Row{
        int next;
        Object* data;
    };

    int capacity;
    Row* rows;
    int head;
*/


FSCursorList::FSCursorList(int capacity){
	this->capacity=capacity;
	head = -1;
}

FSCursorList::~FSCursorList(){
	delete rows;
}
bool FSCursorList::insert(Object* E, int p){
	if(p<0||p>size){
		return false;
	}
	if(size==capacity){
		return false;
	}
	neo = next.avail();
	if(head==-1&&p==0){
		head = neo;
		rows[head] = E;
		rows[head].next=-1;
	}else if(p==0&&head!=-1){
		E->next = rows[head];
		rows[head] = E;
	} else{
		int tmp = head;
		for(int i=0;i<p-1;i++){
			tmp = rows[tmp]->next;
		}
		if(rows[tmp]->next==-1){
			return false;
		}
		E->next = rows[tmp]->next;
		rows[tmp]->next = E;
	}
	size++;
	return true;
}

int FSCursorList::indexOf(Object* E)const{
	int tmp = head;
	for(int i=0; i<size;i++){
		if(rows[tmp].data==E){
			return i;
		}
		tmp = data[tmp].next;
	}
	return -1;
}
Object* FSCursorList::get(unsigned pos)const{
	if(pos<0||p>size){
		return NULL;
	}
	int tmp = head;
	for(int i=0; i<p;i++){
		tmp = rows[tmp].next;
	}
	return rows[tmp].data;
}
Object* FSCursorList::erase(unsigned){
	if(p<0||p>size){
		return NULL;
	}
	Object* E = rows[p].data;
	if(p==0){
		head = rows[p].next;
		rows[p].next=-1;
		rows[p].data=NULL;
	}else if(p==size-1){
		int tmp;
		for(int i=0; i<p-1; i++){
			tmp = rows[tmp].next;
		}
		rows[p].data = NULL;
		rows[tmp].next = -1;
	} else{
		int tmp = head;
		for(int i=0;i<p-1;i++){
			tmp = rows[tmp].next;
		}
		rows[tmp] = rows[rows[p].next];
		if(rows[tmp]==NULL){
			rows[size] = rows[tmp];
		}
		rows[tmp].data = NULL;
		size--;
	}
	return rows[p];
}
int FSCursorList::prev(int pos) const{
	return -1;
}
int FSCursorList::next(int pos) const{
	int tmp = head;
	for(int i=0; i<pos; i++){
		tmp = rows[tmp].next;
	}
	return rows[tmp].next;
}
void FSCursorList::reset(){
	delete rows;
	rows = new Row[size];
	size++;

}
Object* FSCursorList::first()const{
	if(head==-1)
		return NULL;
	return rows[head].data;
}
Object* FSCursorList::last()const{
	int tmp = head;
	for(int i=0; i<size;i++){
		tmp = data[tmp].next;
	}

	return rows[tmp].data;
}
void FSCursorList::print()const{
	int tmp = head;
	for(int i = 0; i< size;i++){
		rows[tmp].data->print();
		tmp = rows[tmp].next;
	}
}
bool FSCursorList::isFull()const{
	if(size==capacity){
		return true;
	}
	return false;
}
int FSCursorList::getCapacity()const{
	return -1;
} 