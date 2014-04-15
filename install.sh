# Pega os arquivos
wget http://www.inf.pucrs.br/~flash/progswb/aulas/lpc2378/arm-toolchain-linux-2.tar.bz2
wget http://www.inf.pucrs.br/~flash/progswb/aulas/lpc2378/lpc21isp-2378.tar.gz
# Expande 
tar xjf arm-toolchain-linux-2.tar.bz2
# Aplica remendo que substitui o lpc21isp e acrescenta o ltser e o lpc23xx.h
tar xzf lpc21isp-2378.tar.gz
# Para funcionar, tem que setar o PATH corretamente no terminal
# Exemplo (supondo que foi descompactado na raiz do user):
export PATH=$PATH:$HOME/arm/bin
echo "Feito. Nao esqueca de setar o PATH"

