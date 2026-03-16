# 📡 TEMA 3 — Governo cortou a verba (Roteadores com pouco cabo)

**Curso:** Técnico em Desenvolvimento de Sistemas — COLTEC  
**Disciplina:** Grafos / Estruturas de Dados  
**Grupo:**  
- Davi Costa  
- Matheus Freitas  
- Maurício Fonseca  
- Rafael Ferreira  

---


## 📖 Descrição do Problema

Você é o responsável por configurar os roteadores do COLTEC. Os roteadores transmitem dados entre si por meio de cabos de rede, e esses dados podem percorrer uma ou mais rotas até chegar ao destino.

Porém, devido ao alto custo dos cabos de rede e ao corte de verba do governo, é necessário **utilizar a menor quantidade possível de cabos**, garantindo que todos os roteadores continuem conectados.

O objetivo do projeto é encontrar a forma **mais econômica de conectar todos os roteadores**, mantendo a comunicação entre eles.

---

## 🎯 Objetivo

Desenvolver um programa que:

- Modele a rede de roteadores como um **grafo**
- Represente os cabos como **arestas com peso (custo ou tamanho)**
- Encontre a melhor forma de conectar todos os roteadores usando **o menor custo possível**
- Evite desperdício de cabos
- Garanta que todos os roteadores consigam se comunicar

---

## 🧠 Conceitos Utilizados

- Grafos
- Árvores Geradoras Mínimas (MST)
- Algoritmo de Kruskal ou Prim
- Estruturas de Dados
- Linguagem C

---

## ⚙️ Funcionamento do Programa

O programa:

1. Recebe a quantidade de roteadores e cabos disponíveis  
2. Lê as conexões possíveis entre os roteadores e seus respectivos custos  
3. Calcula a **Árvore Geradora Mínima**  
4. Exibe:
   - As conexões utilizadas  
   - O custo total mínimo da rede  

---

## 🖥️ Compilação e Execução

No terminal, utilize:

```bash
gcc TrabGrafos.c -o trab
trab
```

---

## 📂 Estrutura do Projeto

```bash
📁 Projeto-Roteadores
 ├── TrabGrafos.c
 └── README.md
```

---

## 🏫 Contexto Acadêmico

Projeto desenvolvido como atividade prática para aplicar conceitos de Grafos e otimização, simulando um problema real de infraestrutura de redes com restrição de recursos.
