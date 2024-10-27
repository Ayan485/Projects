document.getElementById("chat-form").addEventListener("submit", async function (e) {
            e.preventDefault();
            const messageInput = document.getElementById("messageInput");
            const message = messageInput.value;
            if (!message) return;

            // Add user's message to chat box
            const chatBox = document.getElementById("chat-box");
            const userMessageDiv = document.createElement("div");
            userMessageDiv.className = "user-message";
            userMessageDiv.innerText = message;
            chatBox.appendChild(userMessageDiv);
            messageInput.value = "";

            // Send message to backend
            const response = await fetch("/chat", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({ message })
            });

            const data = await response.json();

            // Add bot's response to chat box
            const botMessageDiv = document.createElement("div");
            botMessageDiv.className = "bot-message";
            botMessageDiv.innerText = data.response;
            chatBox.appendChild(botMessageDiv);

            // Scroll to the bottom of the chat box
            chatBox.scrollTop = chatBox.scrollHeight;
        });

        document.getElementById("upload-form").addEventListener("change", async function () {
            const fileInput = document.getElementById("file-input");
            const file = fileInput.files[0];
            if (!file) return;

            const formData = new FormData();
            formData.append("file", file);

            // Show preview of the uploaded image
            const chatBox = document.getElementById("chat-box");
            const userMessageDiv = document.createElement("div");
            userMessageDiv.className = "user-message";
            const imagePreview = document.createElement("img");
            imagePreview.src = URL.createObjectURL(file);
            imagePreview.style.maxWidth = "100%";
            userMessageDiv.appendChild(imagePreview);
            chatBox.appendChild(userMessageDiv);

            const response = await fetch("/upload-image", {
                method: "POST",
                body: formData
            });

            const data = await response.json();

            const botMessageDiv = document.createElement("div");
            botMessageDiv.className = "bot-message";
            botMessageDiv.innerText = 'Image "${data.filename}" uploaded successfully.';
            chatBox.appendChild(botMessageDiv);

            // Scroll to the bottom of the chat box
            chatBox.scrollTop = chatBox.scrollHeight;
        });