import functools

# Decorador para verificar saldo nas contas
def verificar_contas(func):
    @functools.wraps(func)
    def wrapper(self, *args, **kwargs):
        valor = args[0]  # O primeiro argumento é o valor da transação
        
        # Itera sobre as contas e verifica o saldo
        for nome_conta, saldo in self.contas.items():
            if saldo >= valor:
                print(f"Conta '{nome_conta}' possui saldo suficiente ({saldo}). Realizando transação.")
                self.contas[nome_conta] -= valor  # Deduz o valor da conta
                return func(self, nome_conta, valor, *args[1:], **kwargs)
        
        # Se nenhuma conta tiver saldo suficiente
        print(f"Erro: Saldo insuficiente em todas as contas para a transação de {valor}.")
        return False
    return wrapper

# Classe Conta com múltiplas contas
class Conta:
    def __init__(self, contas_iniciais):
        """
        contas_iniciais: dicionário com nomes de contas e seus respectivos saldos.
        """
        self.contas = contas_iniciais

    @verificar_contas
    def realizar_transacao(self, conta_usada, valor):
        print(f"Transação realizada com sucesso da conta '{conta_usada}'. Novo saldo: {self.contas[conta_usada]}")
        return True

# Exemplo de uso
contas_iniciais = {
    'salario': 0,
    'poupança': 100,
    'corrente': 50,
    'investimentos': 300,
}

conta = Conta(contas_iniciais)

# Tentativas de transação
conta.realizar_transacao(50)   # Deve usar a conta 'poupança'
conta.realizar_transacao(200)  # Deve usar a conta 'investimentos'
conta.realizar_transacao(400)  # Deve falhar por saldo insuficiente
