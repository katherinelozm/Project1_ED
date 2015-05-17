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
	return true;
}

int FSCursorList::indexOf(Object*)const{

}
Object* FSCursorList::get(unsigned)const{

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
		Object* obj;
		for(int i=0;i<p-1;i++){
			tmp = rows[tmp].next;
		}
		rows[tmp].next = rows[p].next;

	}

}
int FSCursorList::prev(int pos) const{
	return -1;
}
int FSCursorList::next(int pos) const{

}
void FSCursorList::reset(){

}
Object* FSCursorList::first()const{

}
Object* FSCursorList::last()const{

}
void FSCursorList::print()const{

}
bool FSCursorList::isFull()const{
	if(size==capacity){
		return true;
	}
	return false;
}
int FSCursorList::getCapacity()const{

} 