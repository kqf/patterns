#include <iostream>
#include <string>
#include <map>
#include <stack>

using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::map;


typedef map<char, float> Context;

class Expression
{
public:
    virtual float interpret(Context & variables) const = 0;
};

class Variable: public Expression
{
public:
    Variable(char s): symbol(s) {}
    float interpret(Context & variables) const
    {
        // Crash the program if symbol is not defined
        return variables[symbol];
    }

protected:
    char symbol;
};


// This one is still abstract
class Composite: public Expression
{
public:
    Composite(Expression * l, Expression * r): left(l), right(r)
    {
    }

    virtual ~Composite()
    {
        delete left;
        delete right;
    }

protected:
    Expression * left;
    Expression * right;
};

// This one is still abstract
class Divide: public Composite
{
public:
    Divide(Expression * l, Expression * r): Composite(l, r) {}

protected:
    float interpret(Context & variables) const
    {
        return left->interpret(variables) / right->interpret(variables);
    }

};

// This one is still abstract
class Multiply: public Composite
{
public:
    Multiply(Expression * l, Expression * r): Composite(l, r) {}

protected:
    float interpret(Context & variables) const
    {
        return left->interpret(variables) * right->interpret(variables);
    }

};

// This one is still abstract
class Add: public Composite
{
public:
    Add(Expression * l, Expression * r): Composite(l, r) {}

protected:
    float interpret(Context & variables) const
    {
        return left->interpret(variables) + right->interpret(variables);
    }

};

class Sub: public Composite
{
public:
    Sub(Expression * l, Expression * r): Composite(l, r) {}

protected:
    float interpret(Context & variables) const
    {
        return left->interpret(variables) - right->interpret(variables);
    }

};

Expression * CreateExpression(const string formula)
{
    std::stack<Expression * > stack;

    Expression * left;
    Expression * right;

    for (string::const_iterator i = formula.begin(); i != formula.end(); ++i)
    {
        switch (*i)
        {
        case '*':
            left = stack.top();
            stack.pop();
            right = stack.top();
            stack.pop();
            stack.push(new Multiply(left, right));
            break;

        case '/':
            left = stack.top();
            stack.pop();
            right = stack.top();
            stack.pop();

            stack.push(new Divide(left, right));
            break;

        case '+':
            left = stack.top();
            stack.pop();
            right = stack.top();
            stack.pop();

            stack.push(new Add(left, right));
            break;

        case '-':
            left = stack.top();
            stack.pop();
            right = stack.top();
            stack.pop();

            stack.push(new Sub(left, right));
            break;

        case ' ': break;

        default:
            stack.push(new Variable(*i));
            break;
        }
    }
    return stack.top();
}

int main(int argc, char const *argv[])
{

    // Client code
    Expression * expr = CreateExpression("a b c - +");

    Context context;
    context['a'] = 2;
    context['b'] = 2;
    context['c'] = 3;

    cout << expr->interpret(context) << endl;
    return 0;
}