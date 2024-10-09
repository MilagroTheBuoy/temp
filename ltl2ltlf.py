from parsimonious import Grammar, NodeVisitor

# Define the grammar for propositional logic expressions
grammar = Grammar(
    r"""
    expr           = implication / or_expr
    implication    = or_expr (implication_op or_expr)*
    or_expr        = and_expr (or_op and_expr)*
    and_expr       = unary_expr (and_op unary_expr)*
    unary_expr     = not_expr / primary
    not_expr       = not_op unary_expr
    primary        = symbol / constant / paren_expr
    symbol         = ~"[a-zA-Z][a-zA-Z0-9_]*"
    constant       = "true" / "false"
    paren_expr     = "(" expr ")"
    
    implication_op = "<->" / "<=>" / "iff" / "->" / "=>" / "imp" / "imply" / "implies"
    or_op          = "|" / "or"
    and_op         = "&" / "and"
    not_op         = "-" / "~" / "not"
    """
)

# Define the visitor class to convert the parsed expressions to Python classes
class LogicVisitor(NodeVisitor):
    def generic_visit(self, node, visited_children):
        return visited_children[0]

    def visit_expr(self, node, children):
        return children[0]

    def visit_implication(self, node, children):
        if len(children) == 1:
            return children[0]
        left, *right = children
        return Implication(left, right[1])

    def visit_or_expr(self, node, children):
        if len(children) == 1:
            return children[0]
        left, *right = children
        return Or(left, right[1])

    def visit_and_expr(self, node, children):
        if len(children) == 1:
            return children[0]
        left, *right = children
        return And(left, right[1])

    def visit_unary_expr(self, node, children):
        return children[0]

    def visit_not_expr(self, node, children):
        return Not(children[1])

    def visit_primary(self, node, children):
        return children[0]

    def visit_symbol(self, node, children):
        return Symbol(node.text)

    def visit_constant(self, node, children):
        return Constant(node.text)

    def visit_paren_expr(self, node, children):
        return children[1]

# Define Python classes to represent the logical connectives
class Implication:
    def __init__(self, left, right):
        self.left = left
        self.right = right

class Or:
    def __init__(self, left, right):
        self.left = left
        self.right = right

class And:
    def __init__(self, left, right):
        self.left = left
        self.right = right

class Not:
    def __init__(self, expr):
        self.expr = expr

class Symbol:
    def __init__(self, name):
        self.name = name

class Constant:
    def __init__(self, value):
        self.value = value

# Example usage
def parse_expression(expression):
    tree = grammar.parse(expression)
    visitor = LogicVisitor()
    return visitor.visit(tree)

# Parsing examples
parsed = parse_expression("p -> q")
print(parsed.__class__.__name__)  # Implication

parsed = parse_expression("p or q")
