public class LL {
        private Node head;
        private Node tail;
        private static int size = 0;

        private class Node {
                int value;
                Node next;

                Node(int value) {
                        this.value = value;
                        this.next = null;
                }

                Node(int value, Node next) {
                        this.value = value;
                        this.next = next;
                }
        }

        private void insertFirst(int value) {
                Node node = new Node(value);
                node.next = head;
                head = node;

                if (tail == null) {
                        tail = head;
                }
                size++;

                System.out.println("Added To First");
        }

        private void insertLast(int value) {
                if (tail == null) {
                        insertFirst(value);
                        return;
                }
                Node node = new Node(value);
                tail.next = node;
                tail = node;

                size++;

                System.out.println("Added To Lst");
        }

        private void insertInBetween(int value, int index) {
                int pointer = 1;
                Node temp = head;
                while (pointer < index) {
                        temp = temp.next;
                        pointer++;
                }
                Node node = new Node(value, temp.next);
                temp.next = node;

                size++;
                // node.next = temp.next;
                // temp.next = node;
        }

        private int deleteFirst() {
                int value = head.value;
                if (tail == null) {
                        head = null;
                        tail = null;
                }
                head = head.next;
                size--;
                return value;
        }

        private Node get(int index) {
                Node temp = head;
                for (int i = 0; i < index; i++) {
                        temp = temp.next;
                }
                return temp;

        }

        private int deleteLast(int index) {
                Node temp = get(index - 2);
                int val = tail.value;
                tail = temp;
                tail.next = null;
                return val;
        }

        private int deleteBetween(int index) {
                if (index == 0) {
                        deleteFirst();
                }
                if (index == size) {
                        deleteLast(size);
                }

                Node prev = get(index);
                int val = prev.next.value;

                prev.next = prev.next.next;
                return val;
        }

        private void printList() {
                Node temp = head;
                while (temp != null) {
                        System.out.println(temp.value);
                        temp = temp.next;
                }
                System.gc();
        }

        public static LL merge(LL first, LL second) {
                LL ans = new LL();
                Node f = first.head;
                Node s = second.head;
                while (f.next != null && s.next != null) {
                        if (f.value < s.value) {
                                ans.insertLast(f.value);
                                f = f.next;
                        } else if (s.value < f.value) {
                                ans.insertLast(s.value);
                                s = s.next;
                        } else {
                                ans.insertLast(f.value);
                                f = f.next;
                                s = s.next;
                        }
                }

                while (f.next != null) {
                        ans.insertLast(f.value);
                        f = f.next;
                }
                while (s.next != null) {
                        ans.insertLast(s.value);
                        s = s.next;
                }
                return ans;
        }

        public static void main(String[] args) {
                LL list = new LL();
                list.insertFirst(23);
                list.insertFirst(45);
                list.insertFirst(67);
                list.insertFirst(68);
                list.insertLast(76);
                list.insertInBetween(345, 3);
                System.out.println(list.deleteFirst());
                System.out.println("Deleted" + list.deleteLast(size));
                list.printList();

                LL list2 = new LL();
                list2.insertFirst(3);
                list2.insertFirst(12);
                list2.insertFirst(34);
                list2.insertFirst(54);
                list2.insertLast(91);

                merge(list, list2).printList();
        }
}