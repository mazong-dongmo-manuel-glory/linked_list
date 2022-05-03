class Node{
    constructor(data){
        this.data = data 
        this.next =  null
    }
}
class List{
    constructor(data){
        this.head = new Node(data)
        this._length = 1
    }
    print(){
        let ptr = this.head 
        while(ptr != null){
            console.log(`[${ptr.data}]`)
            ptr = ptr.next
        }
    }
    add(data){
        let ptr = this.head 
        while(ptr.next != null){
            ptr = ptr.next
        }
        ptr.next = new Node(data)
        this._length += 1
    }

    deleteFirst(){
        this.head = this.head.next
        this._length -= 1
    }
    isEmpty(){
        return this.head != null ? false : true
    }
    reverse(){
       let ptr = this.head 
       while(ptr != null){
          
           let j =ptr.next 
           while(j != null){
               let temp = j.data 
               j.data = ptr.data 
               ptr.data = temp 
               j = j.next
           }
           ptr = ptr.next
       }
    }
    sortAsc(){
        let i = this.head
        while(i != null){
            let j = i.next 
            let iMin = i 
            while(j!=null){
                if(iMin.data>j.data){
                    iMin = j
                }
                j = j.next
            }
            let temp = iMin.data 
            iMin.data = i.data 
            i.data = temp 
            i = i.next
        }
    }
    sortDesc(){
        let i = this.head
        while(i != null){
            let j = i.next 
            let iMax = i 
            while(j!=null){
                if(iMax.data<j.data){
                    iMax = j
                }
                j = j.next
            }
            let temp = iMax.data 
            iMax.data = i.data 
            i.data = temp 
            i = i.next
        }
    }
    find(value){
        let i = this.head
        while(i!=null){
            if(i.data==value){
                return true
            }
            i = i.next
        }
        return false
    }
    length(){
        return this._length
    }
}


window.setTimeout(()=>{
    a = new List(10)

for(let i=0;i<10;i++){
    let temp = parseInt(prompt("entrer lage "+i))
    a.add(temp)
}
let state = true
while(state){
    let choix = parseInt(prompt("entrer votre choix :"));
    console.log(typeof choix)
    switch(choix){
        case 1:
            console.clear()
            a.print()
            break 
        case 2:
            console.clear()
            a.sortAsc()
            a.print()
            break
        case 3:
            console.clear()
            a.sortDesc()
            a.print()

            break
        case 4:
            conosle.clear()
            a.reverse()
            a.print()
            break
        case 5:
            console.clear()
            a.deleteFirst()
            a.print()
            break
        default:
            state = false
            break

    }
}

},3000)
