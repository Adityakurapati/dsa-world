public class DLL {
        Node head;

        private class Node {
                int value;
                Node prev;
                Node next;

                public Node(int value) {
                        this.value = value;
                }

                public Node(int value, Node prev, Node next) {
                        this.value = value;
                        this.next = next;
                        this.prev = prev;
                }
        }

        private void insertFirst(int value) {
                Node node = new Node(value);
                node.prev = null;
                if (head == null) {
                        node.next = null;
                } else {
                        node.next = head;
                        head.prev = node;
                }
                head = node;
        }

        private void insertLast(int value) {
                Node node = new Node(value);
                if (head == null) {
                        insertFirst(value);
                        return;
                }
                Node temp = head;
                while (temp.next != null) {
                        temp = temp.next;
                }
                temp.next = node;
                node.prev = temp;
        }

        private void insertInBetween(int value, int index) {
                Node node = new Node(value);

                if (index == 0) {
                        node.next = head;
                        if (head != null) {
                                head.prev = node;
                        }
                        head = node;
                        return;
                }
                int pointer = 1;
                Node prev = head;
                for (int i = 0; i < index && prev != null; i++) {
                        prev = prev.next;
                }

                node.next = prev.next;
                node.prev = prev;
                prev.next = node;
                if (node.next != null) {

                        node.next.prev = node;
                }

        }

        private Node find(int value) {
                Node temp = head;
                while (temp.next != null) {
                        if (temp.value == value) {
                                return temp;
                        }
                        temp = temp.next;
                }
                return temp;
        }

        private void insertAfter(int after, int val) {
                Node node = new Node(val);
                if (head == null) {
                        insertFirst(val);
                        return;
                }
                Node prev = find(val);
                node.prev = prev;
                node.next = prev.next;
                prev.next = node;
                if (node.next != null) {
                        node.next.prev = node;
                }

        }

        private void display() {
                Node temp = head;
                while (temp != null) { // Iterate until the end of the list
                        System.out.println(temp.value);
                        temp = temp.next; // Move to the next node
                }
        }

        private void displayRev() {
                Node temp = head;
                while (temp != null && temp.next != null) {
                        temp = temp.next; // Move to the next node
                }
                while (temp != null) {
                        System.out.println(temp.value + " ");
                        temp = temp.prev;
                }
        }

        public static void main(String[] args) {
                DLL list = new DLL();
                list.insertFirst(0);
                list.insertFirst(3);
                list.insertFirst(7);
                list.insertInBetween(56, 1);
                list.insertLast(77);
                list.display();
                list.displayRev();
        }
}
