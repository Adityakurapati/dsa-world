public class CLL {
        Node head, tail;

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
                }
        }

        private void insert(int value) {
                Node node = new Node(value);
                if (head == null) {
                        head = node;
                        tail = node;
                }

                node.next = head;
                tail.next = node;
                tail = node;
        }
        private void display(){

        }
}
