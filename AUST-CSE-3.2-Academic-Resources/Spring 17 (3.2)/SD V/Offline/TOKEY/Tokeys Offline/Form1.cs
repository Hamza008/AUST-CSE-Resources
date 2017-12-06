using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        CustomerDAO customerDAO = new CustomerDAO();
        public Form1()
        {
            InitializeComponent();
            Dept.Items.Add("CSE");
            Dept.Items.Add("EEE");
            Dept.Items.Add("ME");
            Dept.Items.Add("IPE");
            LoadCustomers();
        }

        private void LoadCustomers()
        {
           customerInfo.DataSource=  customerDAO.GetCustomers().Tables[0];
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void Dept_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(ID.Text),
             age = Convert.ToInt32(Age .Text);
            string name = Name.Text,
             dept = Dept.Text;
            customerDAO.CreateCustomer(new CustomerDTO(id, name, age, dept));

            LoadCustomers();
        }

        private void customerInfo_SelectionChanged(object sender, EventArgs e)
        {
            if (customerInfo.SelectedRows.Count == 1)
            {
                int idx = customerInfo.SelectedRows[0].Index;

                ID.Text = customerInfo.Rows[idx].Cells[0].Value.ToString();
                Name.Text = customerInfo.Rows[idx].Cells[1].Value.ToString();
                Age.Text = customerInfo.Rows[idx].Cells[2].Value.ToString();
                Dept.Text = customerInfo.Rows[idx].Cells[3].Value.ToString();

            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(ID.Text);
            customerDAO.DeleteCustomer(id);
            LoadCustomers();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(ID.Text),
             age = Convert.ToInt32(Age.Text);
            string name = Name.Text,
             dept = Dept.Text;
            customerDAO.UpdateCustomer(new CustomerDTO(id, name, age, dept),id);
            LoadCustomers();

        }

       
    }
}
