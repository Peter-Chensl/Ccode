namespace 学生成绩管理系统
{
    partial class 登录
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(登录));
            this.label3 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.sign_up = new System.Windows.Forms.Button();
            this.sign_in = new System.Windows.Forms.Button();
            this.txtpsd = new System.Windows.Forms.TextBox();
            this.txtName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtUserName = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Location = new System.Drawing.Point(138, 184);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 12);
            this.label3.TabIndex = 24;
            this.label3.Text = "权限";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "学生",
            "教师",
            "管理员"});
            this.comboBox1.Location = new System.Drawing.Point(208, 181);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 20);
            this.comboBox1.TabIndex = 23;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("隶书", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.label1.Location = new System.Drawing.Point(33, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(472, 56);
            this.label1.TabIndex = 22;
            this.label1.Text = "学生成绩管理系统";
            // 
            // sign_up
            // 
            this.sign_up.Location = new System.Drawing.Point(220, 291);
            this.sign_up.Name = "sign_up";
            this.sign_up.Size = new System.Drawing.Size(75, 23);
            this.sign_up.TabIndex = 21;
            this.sign_up.Text = "注册";
            this.sign_up.UseVisualStyleBackColor = true;
            this.sign_up.Click += new System.EventHandler(this.sign_up_Click);
            // 
            // sign_in
            // 
            this.sign_in.Location = new System.Drawing.Point(220, 242);
            this.sign_in.Name = "sign_in";
            this.sign_in.Size = new System.Drawing.Size(75, 23);
            this.sign_in.TabIndex = 20;
            this.sign_in.Text = "登录";
            this.sign_in.UseVisualStyleBackColor = true;
            this.sign_in.Click += new System.EventHandler(this.sign_in_Click);
            // 
            // txtpsd
            // 
            this.txtpsd.Location = new System.Drawing.Point(208, 126);
            this.txtpsd.Name = "txtpsd";
            this.txtpsd.PasswordChar = '●';
            this.txtpsd.Size = new System.Drawing.Size(121, 21);
            this.txtpsd.TabIndex = 19;
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(208, 87);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(121, 21);
            this.txtName.TabIndex = 18;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Location = new System.Drawing.Point(138, 135);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 17;
            this.label2.Text = "密码";
            // 
            // txtUserName
            // 
            this.txtUserName.AutoSize = true;
            this.txtUserName.BackColor = System.Drawing.Color.Transparent;
            this.txtUserName.Location = new System.Drawing.Point(138, 90);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(41, 12);
            this.txtUserName.TabIndex = 16;
            this.txtUserName.Text = "用户名";
            // 
            // 登录
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(500, 329);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.sign_up);
            this.Controls.Add(this.sign_in);
            this.Controls.Add(this.txtpsd);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtUserName);
            this.Name = "登录";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button sign_up;
        private System.Windows.Forms.Button sign_in;
        private System.Windows.Forms.TextBox txtpsd;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label txtUserName;
    }
}

