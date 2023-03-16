<!--
Copyright © 2023 Jakub Piotr Hamerliński

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the 'Software'), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. -->

---
theme: apple-basic
colorSchema: light
lineNumbers: false
title: Object Oriented Programming
fonts:
  provider: none
  sans: Canela Text
  local: Canela Text
layout: fact
---

## Poznan University of Technology
## Version Control Systems
Jakub Piotr Hamerliński

---
layout: image-right
image: 'jim.png'
---

# Version Control Systems
## Agenda
* Git
* GitHub
* GitHub CLI
<br><br><br>
> _"Everything I have I owe to this job... this stupid, wonderful, boring, amazing job."_
Jim Halpert

---

# Version Control Systems
## Git
Git is a version control system that allows you to track changes to your code over time and collaborate with other developers. It helps you keep track of all the changes you make to your code, as well as the changes made by your collaborators.

---

# Version Control Systems
## Git basic operations
There are a few basic operations in Git that you should be familiar with:

1. `git clone`: This command is used to create a local copy of a repository that is hosted on a remote server, such as GitHub.

2. `git add`: This command is used to add changes that you have made to your local repository to the staging area. This means that the changes are ready to be committed, but have not yet been permanently saved to the repository.

---

# Version Control Systems
## Git basic operations
3. `git commit`: This command is used to save changes that have been added to the staging area to the repository. When you commit changes, you should provide a message explaining what changes you made and why.
4. `git push`: This command is used to send your committed changes to a remote repository, such as GitHub.<br>

---

# Version Control Systems
## Git basic operations
These are just a few of the basic operations in Git, but there are many more commands and features available. It's a good idea to familiarize yourself with the basics of Git before diving into more advanced features and workflows

---

# Version Control Systems
## GitHub
GitHub is a web-based platform that is used for version control and collaboration on software projects. It allows developers to work on code together, track changes to the codebase, and roll back changes if necessary. It also provides a platform for users to host and share their software projects with others.

Git is the version control system that GitHub is built on top of. Git allows developers to track changes to a codebase over time, revert back to previous versions of the code, and collaborate with other developers on the same codebase.

---

# Version Control Systems
## GitHub
GitHub provides a user-friendly interface for developers to use Git, as well as a range of tools and features to make collaboration and project management easier.

GitHub is widely used by developers and organizations around the world to host and collaborate on software projects. It is also a popular resource for finding and sharing open-source software projects.

---

# Version Control Systems
## Example GitHub task
1. Create a new repository on GitHub.
2. Clone the repository to your local machine using the `git clone` command.
3. Create a new file in the repository and add some content to it.
4. Use `git add` and `git commit` to add the file to the repository and commit your changes.
5. Push the changes to the remote repository using `git push`.

---

# Version Control Systems
## Example GitHub task
1. Create a new branch in the repository using `git branch`.
2. Checkout the new branch using `git checkout`.
3. Make some changes to a file in the new branch and commit the changes.
4. Push the changes to the remote repository using `git push`.
5. Create a pull request to merge the changes from the new branch into the main branch.

---

# Version Control Systems
## GitHub CLI
GitHub CLI is a command line interface (CLI) tool that allows users to interact with the GitHub service and perform various actions directly from their terminal or command prompt. With GitHub CLI, users can create, clone, and fork repositories, create and edit issues and pull requests, and manage their git repositories and branches.

---

# Version Control Systems
## GitHub CLI
It also provides additional functionality such as the ability to search for repositories and users, and to manage and configure various aspects of their GitHub account. GitHub CLI is designed to be a faster and more efficient way to work with GitHub, and can be used in conjunction with other Git tools or as a standalone tool.

---

# Version Control Systems
## GitHub CLI installation
To install GitHub CLI, you will need to have a recent version of Git and Node.js installed on your system. Once these dependencies are installed, you can follow these steps:
1. Open your terminal or command prompt and enter the following command  `npm install -g gh`
This will install the GitHub CLI tool globally on your system.

---

# Version Control Systems
## GitHub CLI installation
2. Once the installation is complete, you can verify that the GitHub CLI is installed and available by running the following command `gh --version` This should print the version number of the GitHub CLI to your terminal.

---

# Version Control Systems
## GitHub CLI installation
3. If you want to configure the GitHub CLI with your GitHub account, you can run the following command  `gh auth login`. This will open a web browser and prompt you to log in to your GitHub account. Once you have logged in, you will be asked to authorize the GitHub CLI to access your account.

---

# Version Control Systems
## GitHub CLI installation
1. Finally, you can test the GitHub CLI by running a simple command such as `gh repo list`. This should list all of the repositories in your GitHub account.

---

# Version Control Systems
## Example GitHub CLI task
1. Check the status of the repository using the GitHub CLI. To do this, type `gh repo status`
2. Check the history of the repository using the GitHub CLI. To do this, type `gh repo history`
3. Check the list of collaborators on the repository using the GitHub CLI. To do this, type<br>`gh repo list-collaborators`

---

# Version Control Systems
## Example GitHub CLI task
4. Add a collaborator to the repository using the GitHub CLI. To do this, type <br>`gh repo add-collaborator <username>`. Replace `<username>` with the desired username of the collaborator.
5. Remove a collaborator from the repository using the GitHub CLI. To do this, type <br>`gh repo remove-collaborator <username>`. Replace `<username>` with the username of the collaborator you want to remove.

---

# Version Control Systems
## Sources
* [Agenda image](https://octodex.github.com/images/NUX_Octodex.gif "Octocat:)")

---
layout: statement
---

# Thank you
Feel free to reach me via [Linkedin](https://www.linkedin.com/in/hamerlinski/ "Contact me anytime!")

---
layout: statement
---

# *Fin*
