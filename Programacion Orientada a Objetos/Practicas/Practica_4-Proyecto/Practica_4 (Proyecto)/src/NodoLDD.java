public class NodoLDD {
    private String item;
    private int llave;
    private NodoLDD next, prev;
    //++//++//++//++//++//++//++//++//++//++//++//++//++//++
    
    public NodoLDD(){//Constructor por defecto EXPLICITO
    
    }
    
    public NodoLDD(NodoLDD next, NodoLDD prev, String item, int llave){//Constructor personalizado
        this.next = next;
        this.prev = prev;
        this.item = item;
        this.llave = llave;
    }
    
    public String getItem() {
        return item;
    }

    public void setItem(String item) {
        this.item = item;
    }

    public NodoLDD getNext() {
        return next;
    }

    public void setNext(NodoLDD next) {
        this.next = next;
    }

    public NodoLDD getPrev() {
        return prev;
    }

    public void setPrev(NodoLDD prev) {
        this.prev = prev;
    }

    public int getLlave() {
        return llave;
    }

    public void setLlave(int llave) {
        this.llave = llave;
    }
}