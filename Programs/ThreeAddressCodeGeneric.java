import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class ThreeAddressCodeGeneric {
    static String result = "";
    // arranged in increasing order of precedence
    static List<String> operators = new ArrayList<>(Arrays.asList("+", "-", "*", "/", "^"));

    static int getPrecedence(char c){
        switch (c)
        {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }
        return -1;
    }
    static String infixToPostfix(String expression){
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<expression.length(); i++){
            char c = expression.charAt(i);

            // if the character is a letter or a digit
            if(Character.isLetterOrDigit(c))
                result += c;

            // if the character is '('
            else if(c == '(')
                stack.push(c);

            // if the character is ')'
            else if(c == ')'){
                // until the stack is empty or we get '('
                while( !stack.isEmpty() && stack.peek() != '(')
                    result += stack.pop();

                stack.pop(); // popping the '('
            }
            // the character is operator
            else{
                while(!stack.isEmpty() && getPrecedence(c) < getPrecedence(stack.peek()))
                    result += stack.pop();
                stack.push(c);
            }
        }
        while (!stack.isEmpty())
            result += stack.pop();

        return result;
    }

    static List<String> getOperators(List<String> exp){
        List<String> op = new ArrayList<>();
        for(String s: exp){
            if(operators.contains(s))
                op.add(s);
        }
        return op;
    }

    public void generate3AC(String expression){
        String postfix = infixToPostfix(expression);
        String [] expr = postfix.split("");
        List<String> exp = new ArrayList<>(Arrays.asList(expr));
        List<String> operatorsInPostfix = getOperators(exp);

        int i = 0;
        for(String operator : operatorsInPostfix){
            if(exp.contains(operator)){
                for(int j=0; j<exp.size(); j++){
                    if(exp.get(j).equals(operator)){
                        String r = exp.get(j-2);

                        System.out.printf("t%d = %s %s %s\n", i, exp.get(j-1),
                                operator, exp.get(j-2));

                        exp.set(j-1, "t"+i);
                        exp.remove(operator);
                        exp.remove(r);
                        i++;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        String input = "(a+b)*(a-b)";
        System.out.println("Expression: " + input);
        ThreeAddressCodeGeneric threeAddressCodeGeneric = new ThreeAddressCodeGeneric();
        threeAddressCodeGeneric.generate3AC(input);
    }
}