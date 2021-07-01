namespace work
{
    partial class 登录
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(登录));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.sign_up = new System.Windows.Forms.Button();
            this.sign_in = new System.Windows.Forms.Button();
            this.txtpsd = new System.Windows.Forms.TextBox();
            this.txtName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtUserName = new System.Windows.Forms.Label();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("groupBox1.BackgroundImage")));
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.sign_up);
            this.groupBox1.Controls.Add(this.sign_in);
            this.groupBox1.Controls.Add(this.txtpsd);
            this.groupBox1.Controls.Add(this.txtName);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.txtUserName);
            this.groupBox1.Location = new System.Drawing.Point(12, 21);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(432, 307);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "登录";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("隶书", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(27, 41);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(360, 56);
            this.label1.TabIndex = 6;
            this.label1.Text = "图书管理系统";
            // 
            // sign_up
            // 
            this.sign_up.Location = new System.Drawing.Point(159, 262);
            this.sign_up.Name = "sign_up";
            this.sign_up.Size = new System.Drawing.Size(75, 23);
            this.sign_up.TabIndex = 5;
            this.sign_up.Text = "注册";
            this.sign_up.UseVisualStyleBackColor = true;
            this.sign_up.Click += new System.EventHandler(this.sign_up_Click);
            // 
            // sign_in
            // 
            this.sign_in.Location = new System.Drawing.Point(159, 211);
            this.sign_in.Name = "sign_in";
            this.sign_in.Size = new System.Drawing.Size(75, 23);
            this.sign_in.TabIndex = 4;
            this.sign_in.Text = "登录";
            this.sign_in.UseVisualStyleBackColor = true;
            this.sign_in.Click += new System.EventHandler(this.sign_in_Click);
            // 
            // txtpsd
            // 
            this.txtpsd.Location = new System.Drawing.Point(140, 166);
            this.txtpsd.Name = "txtpsd";
            this.txtpsd.PasswordChar = '●';
            this.txtpsd.Size = new System.Drawing.Size(129, 21);
            this.txtpsd.TabIndex = 3;
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(140, 121);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(129, 21);
            this.txtName.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Location = new System.Drawing.Point(65, 175);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "密码";
            // 
            // txtUserName
            // 
            this.txtUserName.AutoSize = true;
            this.txtUserName.BackColor = System.Drawing.Color.Transparent;
            this.txtUserName.Location = new System.Drawing.Point(65, 124);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(41, 12);
            this.txtUserName.TabIndex = 0;
            this.txtUserName.Text = "用户名";
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 354);
            this.splitter1.TabIndex = 1;
            this.splitter1.TabStop = false;
            // 
            // 登录
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.SandyBrown;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(456, 354);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.groupBox1);
            this.Name = "登录";
            this.Text = "登录界面";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button sign_up;
        private System.Windows.Forms.Button sign_in;
        private System.Windows.Forms.TextBox txtpsd;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label txtUserName;
        private System.Windows.Forms.Splitter splitter1;
        private System.Windows.Forms.Label label1;

    }
}